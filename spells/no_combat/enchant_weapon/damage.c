/*
 * this object contain additional hit_functions for a weapon
 * (c) sourcer
 */

int value;

void set_value(int i)
{
	value = i;
}

int magic_hit(object vic)
{
	return value;
}

