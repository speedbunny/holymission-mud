//     Coded by Septian@Holy Mission     //

inherit "room/room";
#include "/players/septian/guild/defs.h"

void reset(int arg)  {
    if (arg)  {

	set_light(1);

	short_desc = "A small dark shop";

	long_desc =
	"You are in a dimly lit shop. There is a sputtering torch on the " +
	"wall and a counter is before you with stained glass between you " +
	"and the shadow behind it. A small sign on the wall next to a slot " +
	"in the counter is here.\n";

	dest_dir = ({
	  "/players/septian/guild/endalley","west"
	});

	items = ({
	  "sign","    Welcome to Shady Deals Inc.     \n" +
	  "                                    \n" +
	  "  We offer a short term insurance   \n" +
	  "  for the interest of your money    \n" +
	  "  and valuables. In turn of a tiny  \n" +
	  "  fee, we can assure you that any   \n" +
	  "  thief you make this agreement     \n" +
	  "  with, will not steal from you     \n" +
	  "  for the duration of your online   \n" +
	  "  time. The thief, if caught not    \n" +
	  "  upholding his bargain, will be    \n" +
	  "  dealt with accordingly. If you    \n" +
	  "  are interested, then fill out     \n" +
       "  the 
" the form that the thief who you   \n" +
" are making the deal with, gives you. \n" +
" Thanks for your business >:)

