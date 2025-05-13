inherit "/obj/armour"; 
#include "/players/beelzebub/misc/defs.h"
#include "/players/beelzebub/guild/extra_look.h"

int guild, level, legend_level, dx, str;
int cant_assassinate=0;
int cant_disarm=0;
int cant_ninjitsu=0;
int cant_stunpunch=0;
int cant_throw=0;
object thispl;

int recognize_fight() {
   object ismed;

   ismed=present("med_obj", environment());

   if(ismed) {
     ismed->destruct(this_object());
     write("You wake up!");
     }

  if(TP->query_invis()){
     TP->set_vis();
     write("You reappear!");
  }
    if(legend_level)
        TP->attack();
    if(level >=10)
        TP->attack();
    if(level >=20)
        TP->attack();
  }

drop () {
    write("You have to leave the guild for that.\n");
    return 1;
}

int id(string str) {
    return (str=="ninjasoul" || str=="guildsoul" || str=="robe" || str=="ninja robe");
}

int check_armor( object plr ) {
   int a, b;
   object *ob;

   ob = all_inventory( plr );
   b = sizeof( ob );

   for( a = 0; a < b; a++ ) {
      if( ob[a] -> query_worn() ) {
         if( !( ob[a] -> query_info() == "nin" ) &&
             !( ob[a] -> query_type() == "ring" ) &&
             !( ob[a] -> query_type() == "amulet" ) &&
             !( ob[a] -> query_type() == "bracelet" ) &&
             !( ob[a] -> query_type() == "ear" ) ) {
            write( "The " + ob[a] -> query_name() + " prevent(s) you from " +
                   "performing this skill!\n" );
            return( 1 );
         }
      }
   }
   return( 0 );
}

int check_weapon( object plr ) {
   int a, b;
   object *ob;

   ob = all_inventory( plr );
   b = sizeof( ob );

   for( a = 0; a < b; a++ ) {
      if( ob[a] -> query_wielded() ) {
         if( !( ob[a] -> query_info() == "nin" ) &&
             !( ob[a] -> query_info() == "ninthrowing" ) ) {
            write( "The " + ob[a] -> query_name() + " prevent(s) you from " +
                   "using this skill!\n" );
	    return( 1 );
         }
      }
   }
   return( 0 );
}

int check_fight( object plr ) {
  if( environment( plr ) -> query_property( "no_fight" ) ) {
     write( "You are not allowed to fight here.\n" );
     return( 1 );
  }
  return( 0 );
}

int check_ghost( object plr ) {
   if( plr -> query_ghost() ) {
      write( "As a ghost, you have no need to perform this skill!\n" );
      return( 1 );
   }
   return( 0 );
}

int check_sp( object plr ) {
   if( plr -> query_sp() <= 0 ) {
      write( "You lack the spellpoints to perform this skill!\n" );
      return( 1 );
   }
   return( 0 );
}

int ninjitsu(int arg){
  if(arg>=0)
    cant_ninjitsu=arg;
  return cant_ninjitsu;
  }

int assassinate(int arg){
  if(arg>=0)
    cant_assassinate=arg;
  return cant_assassinate;
  }

int stunpunch(int arg){
  if(arg>=0)
    cant_stunpunch=arg;
  return cant_stunpunch;
  }

int disarm(int arg){
  if(arg>=0)
    cant_disarm=arg;
  return cant_disarm;
  }

int throw(int arg){
  if(arg>=0)
    cant_throw=arg;
  return cant_throw;
  }

int _cast(string str) {
    string *spellname;
    string newstr;
    int i, j;

    if(!str){
      write("What spell do you want to cast?\n");
      return 1;
    }

    spellname = explode(str," ");
    i = sizeof(spellname);
    if( i > 1 )
        for(j=1;j<i;j++)
            if(j == 1) newstr = spellname[j];
            else newstr = newstr + " " + spellname[j];

    if(file_size(SPELL + spellname[0] + ".c") > 0)
        if ((SPELL + spellname[0])->main(newstr))
            return 1;
    return 0;
}

int _filter(string str) {

    string theverb;

    theverb = (string)query_verb();

    if(theverb[0] == 39) return 0;
    if(theverb == "quit" || theverb == "dest") return 0;
    if(file_size(BIN + theverb + ".c") > 0)
        if ((BIN + theverb)->main(str))
            return 1;
        else return 0;
    if(theverb == "ninja/") {
        (BIN+"ninja")->main(str);
        return 1;
    }
    return 0;
}

void reset(int arg) {
object shadow;
     ::reset (arg);

    if(arg) return;

    guild = GM->query_number("ninja");
    thispl = E();
    set_name("robe");
    set_id("robe");
    set_type("cloak");
    set_info("nin");
    set_short("A black ninja robe");
    set_long("A black ninja robe.\n");
    set_weight(0);
    set_value(0);

    if(TP) {
        TP->set_infravision();
        level = TPL;
        legend_level = TP->query_legend_level();
        dx = TP->DEX;
        str = TP->STR;
        TP->set_n_wc(2 + str/3);
        TP->set_n_ac(6 + dx/3);
    }

    if(!TP->parry_shadow()) {
       shadow = clone_object("/players/beelzebub/guild/shadows/parry_shadow");
       shadow->start_shadow(TP,0, "parry_shadow");
    }
}

void init() {
    
    ::init();
    add_action("_cast","cast");
    add_action("_filter","",1);

    TELL(TP,"You put on your ninja robe and prepare for battle.\n");
    command("wear robe", TP);
    }

