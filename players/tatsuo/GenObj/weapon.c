/*
 * This file defines a general purpose weapon. See below for configuration
 * functions: set_xx.
 */

/*
 * If you are going to copy this file, in the purpose of changing
 * it a little to your own need, beware:
 *
 * First try one of the following:
 *
 * 1. Do clone_object(), and then configure it. This object is specially
 *    prepared for configuration.
 *
 * 2. If you still is not pleased with that, create a new empty
 *    object, and make an inheritance of this objet on the first line.
 *    This will automatically copy all variables and functions from the
 *    original object. Then, add the functions you want to change. The
 *    original function can still be accessed with '::' prepended on the name.
 *
 * The maintainer of this LPmud might become sad with you if you fail
 * to do any of the above. Ask other wizards if you are doubtful.
 *
 * The reason of this, is that the above saves a lot of memory.
 * This object weapon has the advanced feature, that you can set the level,
 * when a player is able to wield it and the state of the object after a
 * fight. */


status wielded;
string wielded_by;
string name_of_weapon;
string state_of_weapon;  /* Whisky */
string cap_name;
string alt_name;
string alias_name;
string short_desc;
string long_desc;
string read_msg;
int class_of_weapon;
int level_of_weapon; /* meaning at which level a player can wield it */
int true_value;      /* shopweapons shouldn't hold too long */
int type_of_weapon;  /* 2: slash, 1: crush, 0: both */
int use_of_weapon;
int value;
int local_weight;
object hit_func;
object wield_func;
string info;
status two_handed;   /* 0: no, 1: yes */

query_name() { return name_of_weapon; }

query_weapon_type() { return type_of_weapon; }

query_state() {
  if(query_use()<=0) 
    state_of_weapon="unusabel";
  else if (query_use()<=400) 
    state_of_weapon="badly damaged";
  else if (query_use()<=800) 
    state_of_weapon="used";
  else if (query_use()<=1000) 
    state_of_weapon="somehow used";
  else
    state_of_weapon="new";
  return state_of_weapon;
 }
  

long() {
  write(long_desc);
  write("It looks "+query_state()+".\n"); /* a player should only recognize */
  if (this_player()->query_wizard())     /* for a wizard */
     write("Usage: "+query_use()+"\n"+
           "Value: "+query_value()+" coins.\n");
}                                 /* by examining it */

reset(arg) {
  if (arg) return;
  wielded = 0; value = 0;
  two_handed=0; type_of_weapon=0;
}

init() {
  if (read_msg) {
    add_action("read", "read");
  }
  add_action("wield", "wield");
}

query_weapon() { return 1; }

wield(str) {
  if (!id(str)) return;
  if (this_player()->query_ghost()) {
    write("You fail.\n");
    say(this_player()->query_name()+" tries to wield "+short_desc+" but fails.\n");
   return 1;
  }
  if (environment() != this_player()) {
    /* write("You must get it first!\n"); */
    return 0;
  } 
  if (level_of_weapon > this_player()->query_str()) {              
     /* too low level players shouldn't wield too strong weapons */
     write("This weapon is much to strong for you.\n");
  return 1;
  }
  if (wielded) {
    write("You already wield it!\n");
    return 1;
  }
  if (wield_conflict()) {            /* e.g try to wield a twohander while */
    write(wield_conflict()+"\n");    /* while wearing a shield             */
    return 1;
  }
  if(wield_func)
    if(!wield_func->wield(this_object())) 
      return 1;
  wielded_by = this_player();
  if(!this_player()->wield(this_object())) 
    return 1;
  wielded = 1;
  write("Ok.\n");
  return 1;
}

short() {
  if (wielded)
    if(short_desc)
      return short_desc + " (wielded)";
  return short_desc;
}

weapon_class() {
  if(query_use()<=0)  
    class_of_weapon=0;
  else  if (query_use()<=400) 
    class_of_weapon=class_of_weapon/2;   /* the class depending on the usage */
  else if (query_use()<=800) 
    class_of_weapon=class_of_weapon*2/3;
  else if (query_use()<=1000) 
    class_of_weapon=class_of_weapon*3/4;
  else 
    class_of_weapon=class_of_weapon;  /* just to be sure */ 
  return class_of_weapon;
}

/* herp */

id(str) {
    return str == name_of_weapon || str == alt_name || str == alias_name;
}

drop(silently) {
  if (wielded) {
    if(!wielded_by->stop_wielding()) return 1;
    wielded = 0;
    if (!silently)
#if 0  /* Changed by Bonzo. 7/7/1992 23:20 */
    write("You drop your wielded weapon.\n");
#endif
#if 1 /* This time, the mess. goes to the right object, not the room. Bonzo. */
    tell_object(wielded_by,"You drop your wielded weapon.\n");
#endif
  }
  return 0;
}

un_wield() {
  if (wielded)
    wielded = 0;
  return 1;
}

hit(attacker) {  /* shit on it (c)Whisky shopweaps shouldn't have that */ 
  use_of_weapon=use_of_weapon-1;
  if (hit_func)          /* just to be sure */
  if(query_use()<=0) 
    return 0;
  else if (query_use()<=400) 
    return hit_func->weapon_hit(attacker/2);
  else if (query_use()<=800) 
    return hit_func->weapon_hit(attacker*2/3);
  else if (query_use()<=1000) 
    return hit_func->weapon_hit(attacker*3/4);
  else
    return hit_func->weapon_hit(attacker);
  return 0;
}

set_id(n) {
  name_of_weapon = n;
  cap_name = capitalize(n);
  short_desc = cap_name;
  long_desc = "You see nothing special.\n";
}

set_name(n) {
  name_of_weapon = n;
  cap_name = capitalize(n);
  short_desc = cap_name;
  long_desc = "You see nothing special.\n";
}

read(str) {
  if (!id(str))
    return 0;
  write(read_msg);
  return 1;
}

wield_conflict() {
  object armours;
  int i,j;

  if(!two_handed) return 0;

  if(environment()->query_armour()[environment()->query_arm_types("shield")])
    return "You have to remove your shield first, if you want to wield the "+
           "twohander.";
}
   

query_value() { 
  if(query_use()<=0)  
    value=value/10; 
  else  if (query_use()<=400) 
    value=value/8;   
  else if (query_use()<=800) 
    value=value/4;  
  else if (query_use()<=1000) 
    value=value/2; 
  else 
    value=value;  
  return value;
}


query_wielded() { return wielded; }

get() { return 1; }

query_weight() { return local_weight; }

query_level() {  /* can be asked in the object */
  if(!level_of_weapon)
      level_of_weapon=this_player()->query_level();
    return level_of_weapon;
  }
   

query_use() {  /* shouldn't work too long */
  if(!use_of_weapon) 
     use_of_weapon=1200;
  return use_of_weapon;
  }
    

query_two_handed() { return two_handed; }

set_class(c) { class_of_weapon = c; }

set_level(l) { level_of_weapon = l; } /* setting the level */

set_use(s)   { use_of_weapon = s; } /* setting how long it can be used */

set_weight(w) { local_weight = w; }

set_value(v) { value = v; }

set_alt_name(n) { alt_name = n; }

set_hit_func(ob) { hit_func = ob; }

set_wield_func(ob) { wield_func = ob; }

set_alias(n) { alias_name = n; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}

set_long(long) { long_desc = long; }

set_read(str) { read_msg = str; }

set_info(i) { info = i; }

set_type(i) { type_of_weapon=i; }

set_two_handed() { two_handed=1; }
 

query_info() { return info; }
