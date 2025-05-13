/* 120593: Airborne: replace_program added for optimization */
/* 020993: Ethereal Cashimor: Orc-guard added against walking orcs */
/* 020993: Airborne: Added Pace's sign */
/* 060993: Ethereal Cashimor: Sign incoorperated in this file */
/* 070993: Ethereal Cashimor: Made sign more clear */
/* 130993: Ethereal Cashimor: Guard now also guards against ogres */
/* 200797: Saffrin:  Redid the all the desc, sign, etc */

inherit "room/room";
#include "/obj/lw.h"
#include "/room/orc/orc.h"
 
object guard,sign,weapon,armour;

void reset(int arg) {

  ::reset(arg);
  if(!guard) {
        guard=clone_object("obj/monster");
        guard->set_name("guard");
        guard->set_level(11);
        guard->set_long(lw("This guard is from the main village " +
                           "and stands here to protect the " +
                           "villagers against the orcs and the ogres " +
                           "from the valley to the west.\n"));
        guard->set_race("human");
        guard->set_gender(2);
        guard->load_chat(1,({"Guard says: Orcs should remain in the valley.\n",
                             "Guard murmers something about orcs.\n",
                             "Guard looks around.\n",
                             "Guard says: I'm a little frightened of ogres.\n",
                             "Guard murmers about bloody ogres.\n"}));
        guard->set_match(this_object(),({"handle_arrival"}),
                                       ({"arrives"}),({""}));
        move_object(guard,this_object());
        weapon=clone_object("obj/weapon");
        weapon->set_name("halberd");
        weapon->set_short("A halberd");
        weapon->set_long(lw("It consists of a battle-axe and a pike " +
                            "mounted on a handle of about six feet " +
                            "long. Some runes indicate another than " +
                            "ordinary purpose.\n"));
        weapon->set_class(13);
        weapon->set_info("This weapon seems to be of slaying orcs and ogres!");
        weapon->set_type(1);
        weapon->set_two_handed();
        weapon->set_hit_func(this_object());
        weapon->set_value(531);
        weapon->set_weight(3);
        armour=clone_object("obj/armour");
        armour->set_name("jacket");
        armour->set_short("A leather jacket");
        armour->set_long(lw("This is brown leather jacket made from rabbit " +
                            "skin.\n"));
        armour->set_ac(1);
        armour->set_type("armour");
        armour->set_size(3);
        move_object(weapon,guard);
        guard->init_command("wield halberd");
        move_object(armour,guard);
        guard->init_command("wear jacket");
  }
  if(arg) return;
  short_desc="A slope";
  long_desc=
            "You are at a slope in the forest.  The trees are lighter here " +
            "and the ground slopes to the west.  There is an arrow that makes " +
            "up a sign pointing to the east of here.  There are some unusal red " +
            "patches seeping from the west.  The forest continue to the north and " +
            "the east of here.\n";
  set_light(1);
  items=({
            "valley","The Orc Valley",
            "red", "Blood red",
            "west", "Orc Valley",
            "east", "Forest",
            "north", "Forest",
            "slope", "A slope to the west",
            "forest","A forest made up of trees",
            "trees","Several trees",
            "blood", "Blood of past victims",
            "patches", "A red stain",
            "arrow", "An arrow making up a sign",
            "sign","It is an old wooden sign in the shape of an arrow, "
                 + "pointing east. It has a map carved onto it... X marks "
                 + "your position.\n"
                 + "\n"
                 + "                 Forest\n"
                 + "                    |\n"
                 + "                    |\n"
                 + "         Orcs* <--- X ---> Forest\n"
                 + "\n"
                 + "Travel brave adventurer, to the marked place *. And seek "
                 + "thy destiny",
  });
  smell="The forest smells fresh but something stinkes to the west.\n";
  dest_dir=({
             "/room/forest8","north",
             "/room/forest10","east",
             ORC+"orc_vall","west",
  });
}

void handle_arrival(string str) {

    string *strexp;
    object who;

    strexp=explode(str," ");
    if(strexp[sizeof(strexp)-1]!="arrives.\n") return;
    who=present(lower_case(strexp[sizeof(strexp)-2]),this_object());
    if(!who) return;
    if(who->query_race()=="ogre") {
        tell_room(this_object(),"Guard says: Ogre, get back in the valley!\n");
        command("west",who);
        return;
    }
    if(who->query_race()!="orc") return;
    tell_room(this_object(),"Guard says: You! Orc! Get back in your valley!\n");
    if(who->query_npc()) command("west",who);
}

int weapon_hit(object who) {

    if(who->query_race()=="orc") {
        write("The halberd glows in a blood red light.\n");
        return 14;
    }
    if(who->query_race()=="ogre") {
        write("The halberd glows with a slime green light.\n");
        return 7;
    }
} 
