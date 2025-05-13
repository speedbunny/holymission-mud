inherit "obj/weapon";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("silly sword");
    set_alt_name("sword");
    set_alias("silly");
    set_class(1);
    set_value(3000);
    set_hit_func(this_object());
    set_short("The Silly Sword");
    set_long("This is the humourous Silly Sword!\n"+
             "It has a face on it's pommel which is very funny to\n"+
             "look at.\n");
    set_hit_func(this_object());
  }
}
 
weapon_hit(arg) {
  int damage,rnd_hit;
  rnd_hit=random(14);
  damage=15+random(10);
  switch(rnd_hit) {
    case 0:
      write("The Silly Sword sings to your opponent, lulling him\n" +
            "into a false sense of security.\n");
      return(damage);
      break;

    case 1:
      write("The Silly Sword throws its voice behind your opponent,\n" +
            "causing your opponent to look back there.\n");
      return(damage);
      break;

    case 2:
      write("The Silly Sword pokes your opponent in the eye.\n");
      return(damage);
      break;

    case 3:
      write("The Silly Sword throws a banana peel and your opponent\n" +
            "slips on it.\n");
      return(damage);
      break;

    case 4:
      write("The Silly Sword stands on its head and claps its hands.\n");
      return(damage);
      break;

    case 5:
      write("The Silly Sword sneezes on your opponent.\n");
      return(damage);
      break;

    case 6:
      write("The Silly Sword pukes on your opponent.\n");
      return(damage);
      break;

    case 7:
      write("The Silly Sword MOONS your opponent!\n");
      return(damage);
      break;

    case 8:
      write("The Silly Sword trips your opponent.\n");
      return(damage);
      break;

    case 9:
      write("The Silly Sword spits in the air then swats the\n" +
            "spit at your opponent.\n");
      return(damage);
      break;

    case 10:
      write("The Silly Sword runs around the room\n screaming: " +
            TP->query_real_name() + " is nuts!!\n" +
            "Your opponent busts a gut laughing.\n");
      return(damage);
      break;

    case 11:
      write("The Silly Sword tickles your opponent, distracting him.\n");
      return(damage);
      break;

    case 12:
      write("The Silly Sword makes funny faces and your opponent\n" +
            "falls down laughing.\n");
      return(damage);
      break;

    case 13:
      write("The Silly Sword sneaks up behind your opponent\n" +
            "and says: BOO!!\n" +
            "Your opponent nearly has a heart attack.\n");
      return(damage);
      break;
  }
}
