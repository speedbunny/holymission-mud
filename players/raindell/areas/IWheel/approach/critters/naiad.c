inherit "obj/monster";
#include "/include/defs.h"

void reset(int arg)
{
::reset(arg);

    if (arg) return;
    set_name("naiad");
    set_alt_name("sprite");
    set_race("sprite");
    set_short("A beautiful naiad");
    set_long("She is a creature of unearthly beauty and grace. The naiad is a shapely\n" 
           + "sprite, her body the form of a healthy young woman down to her hips, and\n"
	     + "possibly beyond, but you cannot tell. Her skin seems almost like water\n"
	     + "itself, deep and blue and impossibly lovely as it flows over her form.\n"
           + "She stands apparently waist high in the water, but oddly, you can't see\n"
  	     + "anything beneath her where her legs should be. It is as if she is part\n"
 	     + "of the river itself. She is dressed sparingly, wearing only a slender\n"
           + "halter made from river plants, just barely enough to preserve modesty.\n"
	     + "With an innocent smile on her smooth blue lips, cool green eyes gaze\n"
	     + "out with a look of quiet seduction.\n");
    set_gender(2);
    set_level(10);
    set_hp(230);
    set_ac(3);
    set_wc(12);
    set_dead_ob(TO);
}

monster_died( arg ) {    
	write("The naiad sighs with disappointment and falls into the river, vanishing.\n"); 
	destruct( arg );
 return( 1 ); 
}
