#include "BinarySearchTree.h"

void initialize(tree* tree)
{
	tree->root = NULL;
	tree->size = 0;
}

void	free_fruit(node* fruit)
{
	free(fruit->data.ev.name);
	free(fruit->data.ev.value);
	free(fruit);
}

node* find_env(tree* envs, char *name)
{
	node* cur;
	int		cmp;

	if (envs->root == NULL)
		return (NULL);
	cur = envs->root;
	while (cur != NULL && name != NULL)
	{
		cmp = ft_strcmp(cur->data.ev.name, name);
		if (cmp == 0)
			return (cur);
		else if (cmp < 0)
			cur = cur->rchild;
		else
			cur = cur->lchild;
	}
	return (NULL);
}

void	print_envs(node* cur, _Bool is_export)
{
	if (cur == NULL)
		return ;
	print_envs(cur->lchild, is_export);
	if (is_export == TRUE)
	{
		printf("declare -x ");
		if (cur->data.ev.value == NULL)
			printf("%s\n", cur->data.ev.name);
		else
			printf("%s=\"%s\"\n", cur->data.ev.name, cur->data.ev.value);
	}
	else
	{
		if (cur->data.ev.value != NULL)
			printf("%s=%s\n", cur->data.ev.name, cur->data.ev.value);
	}
	print_envs(cur->rchild, is_export);
}

static _Bool	insert_env_recur(node* cur, node* new)
{
	int		cmp;

	if (cur == NULL)
		return (TRUE);
	cmp = ft_strcmp(cur->data.ev.name, new->data.ev.name);
	if (cmp < 0)
	{
		if (insert_env_recur(cur->rchild, new))
			cur->rchild = new;
	}
	else
	{
		if (insert_env_recur(cur->lchild, new))
			cur->lchild = new;
	}
	return (FALSE);
}

void	insert_env(tree* tree, t_env_var ev)
{
	node* new;
	node* cur;

	if (tree->size >= 5000)
		return ;
	cur = find_env(tree, ev.name);
	if (cur == NULL)
	{
		new = (node* )ft_calloc(1, sizeof(t_fruit));
		new->data.ev = (t_env_var){ev.name, ev.value};
		if (tree->root == NULL)
			tree->root = new;
		else
			insert_env_recur(tree->root, new);
		++(tree->size);
	}
	else if (ev.value != NULL)
	{
		free(cur->data.ev.name);
		free(cur->data.ev.value);
		cur->data.ev = (t_env_var){ev.name, ev.value};
	}
	else
		free(ev.name);
}

static t_env_var	get_min_ev(node* cur)
{
	while (cur->lchild != NULL)
		cur = cur->lchild;
	return (cur->data.ev);
}

static node* terminate_env(tree* tree, node* cur)
{
	node* temp;

	--(tree->size);
	if (tree->size == 0)
		tree->root = NULL;
	if (cur->rchild == NULL)
	{
		temp = cur->lchild;
		if (cur == tree->root)
			tree->root = temp;
		free_fruit(cur);
		return (temp);
	}
	else
	{
		temp = cur->rchild;
		if (cur == tree->root)
			tree->root = temp;
		free_fruit(cur);
		return (temp);
	}
}

node* erase_env(tree* tree, node* cur, char *name)
{
	int			cmp;
	t_env_var	temp_ev;

	if (cur == NULL)
		return (NULL);
	cmp = ft_strcmp(cur->data.ev.name, name);
	if (cmp < 0)
		cur->rchild = erase_env(tree, cur->rchild, name);
	else if (cmp > 0)
		cur->lchild = erase_env(tree, cur->lchild, name);
	else
	{
		if (cur->lchild == NULL || cur->rchild == NULL)
			return (terminate_env(tree, cur));
		temp_ev = get_min_ev(cur->rchild);
		free(cur->data.ev.name);
		free(cur->data.ev.value);
		cur->data.ev = (t_env_var){ft_strdup(temp_ev.name),
			ft_strdup(temp_ev.value)};
		cur->rchild = erase_env(tree, cur->rchild, temp_ev.name);
	}
	return (cur);
}

static void	destroy_tree_ev_recur(node* cur)
{
	if (cur == NULL)
		return ;
	destroy_tree_ev_recur(cur->lchild);
	destroy_tree_ev_recur(cur->rchild);
	free_fruit(cur);
}

void	destroy_tree_ev(tree* *tree)
{
	destroy_tree_ev_recur((*tree)->root);
	free(*tree);
	*tree = NULL;
}