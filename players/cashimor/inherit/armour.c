#define SHARE "obj/share"
/*
 * This file defines a general purpose armour. See below for configuration
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
 * 2. If you still are not pleased with that, create a new empty
 *    object, and make an inheritance of this objet on the first line.
 *    This will automatically copy all variables and functions from the
 *    original object. Then, add the functions you want to change. The
 *    original function can still be accessed with '::' prepended on the name.
 *
 * The maintainer of this LPmud might become sad with you if you fail
 * to do any of the above. Ask other wizards if you are doubtful.
 *
 * The reason of this, is that the above saves a lot of memory.
 */
/* Changed by Ethereal Cashimor, 100393, included read */

string name, alias, short_desc, long_desc, value, weight;
string type,readstr;
int worn, ac, size,NUMBER_OF_SIZES;
object worn_by;       /* object that wears the armour     */
string info;
string sizes;         /* sizes of armours */
status unwearable;    /* nobody can wear this armour if 1 */

reset(arg) {
  if(arg)
    return;
  type = ({ "armour" });
  size = 0;
  unwearable=0;
  sizes = SHARE->share_armour_sizes();
  NUMBER_OF_SIZES=sizeof(sizes)-1;
}
 
init() {
  add_action("wear", "wear");
  add_action("remove", "remove");
  add_action("read","read");
}
 
read(str) {
  if((!str)||(!id(str))) {
    notify_fail("Read what?\n");
    return 0;
  }
  if(!readstr) {
    notify_fail("There's nothing written on it!\n");
    return 0;
  }
  say(this_player()->query_name()+" reads "+lower_case(short_desc)+".\n");
  write(readstr);
  return 1;
}

short() {
  if (!short_desc)
    return 0;
  if (worn)
    return short_desc + " ("+sizes[size]+")"+" (worn)";
  return short_desc + " ("+sizes[size]+")";
}
 
long(str) {
    write(process_string(long_desc));
}

fix_weight() { /* Moonchild 281092 */
  if(!ac || type[0]=="guild") return;
  if(ac>4) if(weight<(ac*2-3)) return weight=ac*2-3;
  if(ac==4) if(weight<5) return weight=5;
  if(ac==3) if(weight<3) return weight=3;
  if(ac==2) if(weight<2) return weight=2;
  if(type[0]=="shield" || type[0]=="boot") if(weight<2) return weight=2;
  if(weight<1) weight=1;
}

id(str) {       /* An armour identifies to its name, its alias and its type */
  return str == name || str == alias || str == type[0];
}

query_armour() { return 1; }
 
query_type() { return type[0]; }

get_type() { if (stringp(type)) type=({ type }); return type; }
 
query_value() { return value; }
 
query_worn() { return worn; }
 
query_unwearable() { return unwearable; }

query_name() { return name; }
 
armour_class() { return ac; }

set_read(str) {
  readstr=str;
}

query_read() {
  return readstr;
}
 
wear(str) {                /* Armours can be worn (really ?)                 */
  object ob,wea;

  if (this_player()->query_ghost()) {
     write("You fail.\n");
     say(this_player()->query_name()+" failed to wear "+short_desc+".\n");
     return 1;
  }
  wea=this_player()->query_wielded_weapon();
 
  if (!id(str))
    return 0;
  if (environment() != this_player()) return 0;
  if (worn) {                                /* You try to wear an armour you */
    write("You already wear it!\n");         /* already wear (foolishly)      */
    return 1;
  }
  if(unwearable) {
    write(short_desc+" cannot be worn by players.\n");/* unwearable armour   */
    return 1;
  }
  if(size!=0 && size!=this_player()->query_size()) {  /* you try to wear the */
    write(short_desc+" doesn't fit.\n");              /* wrong size          */
    return 1;
  }
  if(query_type()=="shield" && wea && wea->query_two_handed()) {
    write("You cannot wear a shield, while wielding a twohanded weapon.\n");   
    return 1;
  }

  /* 920915 Herp: check the valid types and max.ac */
  if (ac>0) {
     int i,j,k,ta;
     string types;
     int max_ac;

     types  = SHARE->share_armour_types();
     max_ac = SHARE->share_armour_max_ac();

     k=0;
     for (i=0;i<sizeof(type);i++) {
         j=member_array(type[i],types);
         if (j!=-1) k+=max_ac[j];
     }	
     if (k<ac) {
	write("You get a strange feeling wearing the "+short_desc+".\n"
	+   "You decide to remove it.\n");
	log_file("ILLEGAL",ctime(time())+":\n");
        log_file("ILLEGAL",this_player()->query_real_name()+" wear, AC "
	+	ac+" "+short_desc+"("+type[0]+") "
	+	" creator: "+creator(this_object())+" "
	+	file_name(this_object())+"\n");
        return 1;
     }
  } 

  ob=this_player()->wear(this_object());              /* wearing ok.        */
  if(!ob) {
    worn_by = this_player();
    worn = 1;
    return 1;
  }
  if(type[0]=="ring") {
    write("You find no place to put the ring on your finger.\n");
  } else {
    write("You already have an armour of class " + type[0] + ".\n");
    write("Worn armour " + ob->short() + ".\n");
  }

  return 1;
}
 
get() { return 1; }                             /* You can take an armour */
 
drop(silently) {                                /* You can drop it        */
  if (worn) {
    worn_by->stop_wearing(this_object());
    worn = 0;
    worn_by = 0;
    if (!silently)
      tell_object(environment(this_object()),"You drop your worn armour.\n");
  }
  return 0;
}
 
remove(str) {                                    /* You can remove it     */
  if (!id(str)) return 0;
  if (!worn) return 0;
  worn_by->stop_wearing(this_object());
  worn_by = 0;
  worn = 0;
  return 1;
}
 
 
set_id(n) { name = n; }
set_name(n) { name = n; }
set_short(s) { short_desc = s; long_desc = s + ".\n"; }
set_value(v) { value = v; }
set_weight(w) { weight = w; fix_weight(); } /* Moonchild 281092 */
set_ac(a) { ac = a; fix_weight(); } /* Moonchild 281092 */
set_alias(a) { alias = a; }
set_long(l) { long_desc = l; }
set_unwearable() { unwearable=1; }

/* herp: no confusion about armour vs. armor anymore ! */

set_type(t) { 
  t=="armor"?(t="armour"):(t=t);
  type= explode(t,"/");
}
set_arm_light(l) { set_light(l); }

set_size(v) { 
int i;
  if (stringp(v)) {
    for(i=0;i<sizeof(sizes);i++)
	if (v==sizes[i]) break;
  } else i=v; 
  if(i<0 & i>NUMBER_OF_SIZES) i=0;
  size = i;
}

set_info(i) { info = i; }
 
query_weight() { return weight; }
query_info() { return info; }
query_size() { return size; }
 
query_size_name(i) {
  if(i==-1) return sizes[size];
  return sizes[i];
}
