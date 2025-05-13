#define NAME "whisky"
#define DEST "/players/whisky/workroom"

/*
 * This is just the facade to a castle. If you want to enable the "enter"
 * command, move the player to a hall or something (which you have to design
 * yourself). The predefined string DEST is where a player should come when
 * he leaves the castle.
 * 
 * This file is loaded automatically from "init_file". We have to move ourself
 * to where we are supposed to be.
 */

object          ob, ob2, ob3, ob4, ob5, trash, wolf;
int             i;
id(str)
{
    return str == "castle";
}

short()
{
    return "Castle of " + NAME;
}

long()
{
    write("This is the " + short() + ".\n");
    write(NAME + " is a rather new wizard, but it is an amazing castle\n");
    write("just the same. However, the gates are closed.\n");
}

init()
{

    add_action("enter", "enter");
}

enter(str)
{
    if (!id(str))
	return 0;
    write("It is not an open castle.\n");
    return 1;
}

make_quest()
{
    ob = clone_object("obj/quest_obj");
    ob2 = clone_object("obj/quest_obj");
    ob3 = clone_object("obj/quest_obj");
    ob4 = clone_object("obj/quest_obj");
    ob5 = clone_object("obj/quest_obj");
    ob->set_name("witchquest");
    ob2->set_name("millquest");
    ob3->set_name("starburst_quest");
    ob4->set_name("free_zenzi");
    ob5->set_name("free_solar");
    ob->set_weight(30);
    ob2->set_weight(9);
    ob3->set_weight(80);
    ob4->set_weight(5);
    ob5->set_weight(60);
    ob->set_killing(9);
    ob2->set_killing(1);
    ob3->set_killing(15);
    ob4->set_killing(4);
    ob5->set_killing(20);
    ob->set_short_hint("Help the little girl in Chantilly's garden");
    ob->set_hint("Help the little girl near Chantilly's garden to free\n" +
		 "her brother. This quest is solvable from level 5 on.\n" +
		 "But well, it's not so easy and it will take some \n" +
		 "intellectual power and caution.\n\n" +
		 "Good luck Whisky...\n");
    ob2->set_short_hint("Help Hobbe to get his water-mill working");
    ob2->set_hint("Help Hobbe to get his water-mill working and the\n" +
		  "inhabitants of Holy Mission to get their flour\n" +
		  "for their daily morning-rolls.\n\n" +
		  "This quest is solvable on each level !\n\n\n" +
		  "Have fun, Patience & Whisky ....\n");
    ob3->set_short_hint("Help the elfcity to get rid of the big wolf");
    ob3->set_hint("Once upon a time one of the bravest elfwarriors wanted to kill one\n" +
	   "of the biggest dragons in the western part of Holy Mission.\n" +
     "Therefore he trained an extremly strong black wolf for the fight.\n" +
	"But he died and the big wolf ran, badly hurt, into the swamps.\n" +
		  "The item the elfwarrior lost to train his wolf was never found again.\n\n" +
		  "From this time on the wolf came into the elfcity several times and killed\n" +
    "citizens. One of the wisest men of the city once said that the wolf\n" +
     "is only killable with a weapon that reconciles the power of the\n" +
		  "universe.\n\n" +
    "But no brave adventurer was ever found for this dangerous job !\n\n\n" +
	   "Well, this quest is for the best adventurers and you should\n" +
	  "only start it when you have great powers and know most parts of\n" +
		  "Holy Mission !\n\n" +

                  "           Have much fun Whisky && Llort :*)\n");
     ob4->set_short_hint("Free the Major's daughter");
     ob4->set_hint(
     "Rumors are told that Zenzi the daughter of the Major\n"+
     "was caught by evil goblin bandits. People fear that\n"+
     "the Golblin's  might eat her one day when there is no\n"+
     "Hero found to help. Wuntvor the Mage had already located \n"+
     "this evil goblin gang somewhere under the monk's chapel.\n\n"+
     "This Quest is also solvable for low level players :*)\n\n\n"
     "                       Have Fun Whisky.\n");
     ob5->set_short_hint("Free the Solar from Kantele's Castle");
     ob5->set_hint(
     "Rumors are told, that Kantele the Witch has prisoned a\n"+
     "beautiful Solar in her castle. But, even prisoned the\n"+
     "Solars power is that strong, that Kantele herself was't\n"+
     "able to kill him. Therefore Kantele is making a trip to\n"+
     "get a strong magic item, which shall dublicate the power\n"+
     "of her spells.\n"+
     "Your task is now to free that poor Solar out of the hands\n"+
     "of Kantele's evil army, before it is too late.\n\n"+
     "This Quest is best to solve with a group of very strong friends.\n"+
     "Begin your search best on the dragon island east of this world.\n\n"+
     "             Much fun and don't die Whisky :)\n");

    ob->add_quest();
    ob2->add_quest();
    ob3->add_quest();
    ob4->add_quest();
//    ob5->add_quest();
}

monster_clone()
{
object d;

   call_other("/room/vill_road2","???");
   d = find_object("/room/vill_road2");
   if (!find_living("fluffy") && d)
   {
       move_object(clone_object("/players/whisky/tree/monster/fluffy"),
                   d);
   }
}

reset(arg)
{
     monster_clone();
   /*
     if (!find_object("/players/whisky/houses/swifto/house"))
          call_other("/players/whisky/houses/swifto/house","???");
   */

 /*
    if (!present("xxxx",find_object("/room/church") ) )
    {
     call_other("/players/whisky/obj/soulchecker","????");
     move_object(clone_object("/players/whisky/obj/soulchecker"),
                 "/room/church");
    }
   */
    if (arg) return;
    enable_commands();
    call_other("players/whisky/quest/room/ravine1", "??");
//    call_other("/players/whisky/tmp/my_replace","???");
    move_object(clone_object("players/whisky/shops/trashcan"),
                "room/main_shop");
    move_object(this_object(), DEST);
}

query_name() { return "Castle"; }
query_real_name() { return "castle"; }
