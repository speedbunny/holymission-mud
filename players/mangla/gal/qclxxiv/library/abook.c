inherit "/players/qclxxiv/library/book";
reset(arg)
{
	::reset(arg);
	if (arg) return;
	set_bookfile("/players/qclxxiv/library/abook.txt");
}
