/*
 * the object that causes the silence.
 */

inherit "/obj/thing";

void reset(int arg)
{
	if(arg) return;
	::reset(arg);

}

void init()
{
	::init();
	add_action("a_say","say");
	add_action("a_tell","tell");
	add_action("a_say","'");
	add_action("a_shout","shout");
}

int a_say()
{
	write("You try to speak but no voice leaves your throat.\n");
	say(this_player()->query_name()+" opens his mouth but no more happens.\n");
	return 1;
}

int a_tell()
{
	a_say();
	return 1;
}

int a_shout()
{
	a_say();
	return 1;
}



