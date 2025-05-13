#include "/players/tamina/defs.h"

inherit "obj/armour";
int lighted, invis, shield_on;

reset(arg) {
  ::reset(arg);

  if(arg) return;
    
    lighted = 0;
    invis = 0;
    shield_on = 0;

    set_alias("hat");
    set_type("helmet");
    set_short("A Felt Hat");
    set_long("A large, pointed felt, hat made of a dark, soft material.\n"+
             "However, a strange aura of power eminating from it would\n"+ 
             "seem to sugest magical properties of some sort... \n");
    set_value(800);
    set_ac(1);
    set_size(3);
    set_weight(2);

}
query_mage_wear() {  return 1;  }
query_monk_wear() {  return 1;  }

init()
{
  ::init();
  AA("light_on",    "light");      /*   Turns the light of the hat on  */
  AA("light_off",   "dark");       /*   Turns the light of the hat off */
  AA("go_invisible","hide");       /*   Makes wearer invisible         */
  AA("go_visible",  "show");       /*   Makes wearer visible	       */
  AA("shielder",    "protect");    /*   Adds more protection to wearer */
}

int light_on(string str)
{
  if (str == "me")
  {
    if (lighted)
    {
      write("But Merlin's Hat is already providing light for you.\n");
      return 1;
    }
    set_light(1);
    write("Merlin's Hat sheds a degree of light around you.\n");
    say("A burst of light spouts forth from "+TPN+"'s Hat.\n");

    lighted = 1;
    return 1;
  }
}

int light_off(string str)
{
  if (str == "me")
  {
    if (!lighted)
    {
      write("But Merlin's Hat is not lighted at this time.\n");
      return 1;
    }
    set_light(-1);
    write("You concentrate for a moment, and cause the light eminating\n"+
          "Merlin's Hat to flicker into non-existence.\n");
      say("The light eminating from "+TPN+"'s Hat blinks out.\n");

    lighted = 0;
    return 1;
  }
}

int go_invisible(string str)
{
  if (str == "me")
  {
    if (invis)
    {
      write("But Merlin's Hat is already making you unseen to everyone else.\n");
      return 1;
    }
    write("Merlin's Hat extends its power of invisibility over you.\n"+
          "You are no longer seen in the room.\n");
      say(TPN+"'s hat extends over his body, and then suddenly disappears.\n");

    TP->set_invis();
    invis = 1;

    return 1;
  }
}

int go_visible(string str)
{
  if (str == "me")
  {
    if (!invis)
    {
      write("But Merlins's Hat is not making you invisible.\n");
      return 1;
    }
    write("You suddenly appear in the room.\n");
    say(TPN+" appears as if from no where!\n");

    TP->set_vis();
    invis = 0;

    return 1;
  }
}

int shield(string str)
{
  if (str == "me") 
  {
    if (shield_on)
    {
      write("Merlin's Hat already has one shield protecting you.\n"+
   	    "Only one shield can be sustained at any one time.\n");
      return 1;
    }
    write("A peculiar soft blue aura is emitted from Merlin's Hat.\n"+
          "It starts to flicker around you.  You feel more safe.\n");
      say("A soft blue aura flickers around "+TPN+".\n");

    shield_on = 1;

    return 1;
  }
}

