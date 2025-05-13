
inherit "/obj/treasure";

void reset(int arg)
{
  set_name("paper");
  set_alt_name("letter");
  set_short("a sheet of paper");
  set_long("There is something written on it.\n");
  set_value(2);
}

init()
{
  ::init();
  add_action("do_read","read");
}

int do_read(string arg)
{
   if (arg!="paper" && arg!="sheat of paper") return 0;
   write(
   "Hi my holy friend Andoan !\n\n"+
   "Deep in the dangerous forest of fear is a strange ruby.\n"+
   "This item is enchanted by evil powers and forces fear to\n"+
   "anyone looking at it. I myself the old magemaster of Arcanton,\n"+
   "wanted this strange ruby for my own use, just to get rid of the\n"+
   "big dragon which occopied my tower. But for dispeling the curse\n"+
   "of the ruby I needed a scroll of 'despel evil', which should be\n"+
   "brought over the Crecent Lake by a ferry.\n\n"+
   "But just before the ferry cound dock on my island a big waterdemon\n"+
   "took it down with him to the bottom of the lake.\n"+
   "I searched, but the scroll was never found.\n\n"+
   "That's what I beg you now is, if possible to get me a new scroll.\n"+
   "This dragon is really wired.\n\n"+
   "                    ** sigh ** Xeril the Magemaster\n\n");
   return 1;
}

