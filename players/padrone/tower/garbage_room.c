/* This room contains parodies of some well-known monsters and objects */

inherit "/room/room";

#include "../config.h"

object dragon, bralrog, demoon, sirpit, creature, knight, vumpire;
object boomsgiver, guttripper, excalibor;

object nerd_monster(string name,string alias,string short_desc,string long_desc) 
{
    object temp;

    temp = clone_object("obj/monster");
    temp->set_name(name);
    temp->set_alias(alias);
    temp->set_level(1);
    temp->set_hp(30);
    temp->set_wc(2);
    temp->set_al(0);
    temp->set_short(short_desc);
    temp->set_long(long_desc);
    temp->set_aggressive(0);
    temp->set_spell_mess1("The " + name + " says: Help! Help!");
    temp->set_spell_mess2("The " + name + " says: Help! Help!");
    temp->set_chance(30);
    move_object(temp, this_object());
    return temp;
} /* nerd_monster */

object nerd_weapon(string name,string alias,string short_desc,string long_desc) 
{
    object temp;

    temp = clone_object("obj/weapon");
    temp->set_name(name);
    temp->set_alias(alias);
    temp->set_short(short_desc);
    temp->set_long(long_desc);
    temp->set_class(2);
    temp->set_value(20);
    temp->set_weight(2);
    return temp;
} /* nerd_weapon */

object nerd_treasure(string name,string alias,string short_desc,string long_desc) 
{
    object temp;

    temp = clone_object("obj/treasure");
    temp->set_id(name);
    temp->set_alias(alias);
    temp->set_short(short_desc);
    temp->set_long(long_desc);
    temp->set_value(10);
    temp->set_weight(1);
    move_object(temp, this_object());
    return temp;
} /* nerd_treasure */

void reset(int flag) 
{
   object junk_cmd;

   if (!dragon)
   {
     dragon = 
     nerd_monster("clesetial dragon", "dragon", "Palading the clesetial dragon",
     "This monster looks almost, but not quite, like a celestial dragon.\n");
   }
   if (!bralrog)
   {
        bralrog = nerd_monster("bralrog", "demon", "A bralrog",
        "This monster looks almost, but not quite, like a balrog.\n");
   }
   if (!demoon)
   {
        demoon = nerd_monster("demoon", "demon", "A summoned demoon is here",
        "This monster looks almost, but not quite, like a demon.\n");
   }
   if (!sirpit) 
   {
	sirpit = nerd_monster("evil sirpit", "sirpit", "An evil sirpit",
        "This monster looks almost, but not quite, like an evil spirit.\n");
	boomsgiver = nerd_weapon("boomsgiver", "sword", "Boomsgiver",
        "This is not a very powerful sword. You feel no magic aura\n" +
        "surrounding it. There is nothing written on it.\n");
	move_object(boomsgiver, sirpit);
    }

    if (!creature) 
    {
	creature = 
        nerd_monster("laughsome creature", "creature", "A laughsome creature",
	"This monster looks almost, but not quite, like a loathsome creature.\n");
	guttripper = nerd_weapon("guttripper", "Guttripper", "Guttripper",
        "You can only guess what strange deeds this nice tool was used for.\n" +
        "It should serve very badly as a weapon though.\n");
	move_object(guttripper, creature);
	call_other(creature,"init_command", "wield guttripper");
    }
    if (!knight) 
    {
	knight = nerd_monster("block knight", "knight", "A block knight",
        "This monster looks almost, but not quite, like a black knight.\n");
	excalibor = nerd_weapon("excalibor", "sword", "Excalibor",
				"How strange, to make a sword of rubber!\n");
	move_object(excalibor, knight);
	call_other(knight,"init_command", "wield excalibor");
    }

    if (!vumpire)
    {
	vumpire = nerd_monster("vumpire", "vumpire", "A vumpire",
       "This monster looks almost, but not quite, like a vampire.\n");
    }

#ifndef GENESIS
    /* For some reason, Lars didn't like my defective emote command. Pout. */
    if (!present("defective force command", this_object())) {
	junk_cmd = clone_object("players/padrone/obj/def_force");
	move_object(junk_cmd, this_object());
    }
    if (!present("defective emote command", this_object())) {
	junk_cmd = clone_object("players/padrone/obj/def_emote");
	move_object(junk_cmd, this_object());
    }
#endif

    if (!present("amulet", this_object())) 
    {
	nerd_treasure("small non-magical amulet", "amulet",
		      "A small non-magical amulet",
		      "A small non-magical amulet.\n");
	nerd_treasure("large non-magical amulet", "amulet",
		      "A large non-magical amulet",
		      "A large non-magical amulet.\n");
    }

    if (flag == 0)
    {
      set_light(1);
      short_desc = "The garbage room, inside Padrones castle";
      long_desc =
      "You are standing in a small, windowless room.\n" +
      "This is the Wizard's garbage room, where he hides\n" +
      "the results of his failed experiments.\n";
      dest_dir = ({
          "players/padrone/tower/lab", "west",
      });
    }
}
