inherit "/players/qclxxiv/library/book";
reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_color("black");
	set_covertext("Automagical Index of the library\n" );
	set_bookfile("/players/qclxxiv/library/index.txt");
}
short() { return "A "+color+" index"; }

id(arg) { return (::id(arg) || arg=="index"); }
