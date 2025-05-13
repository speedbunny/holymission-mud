inherit "obj/weapon";
#define GM "guild/master"
#define TICKS 10
#define COLS ({ "black","red","orange","blue","violet","green","white" })
#define TP wielded_by
 
int is_sword,count;
 
reset(arg) {
  set_alias("handle");
  set_name("lightsaber");
  set_type(2);
  set_class(5);
  set_weight(1);
  set_read("This is the weapon of a Jedi!\nThe Force is with you!\n");
  handle_reset();
}

id(str) { 
  return str==name_of_weapon || str==alias_name || (str=="blade" && is_sword)
      || str=="button";
}
 
short() {
  string m;
  if(is_sword) m="A "+query_color()+"-bladed lightsaber";
  else m="A simple handle";
  if(wielded) m=m+" (wielded)";

  return m;
}

long(str) {
  if(str=="button") {
    write("A simple button.\n");
    return;
  }
  if(str=="blade") {
    write("It glows in a "+query_color()+" light. It seems to be very dangerous.\n");
    return;
  }

  if(is_sword) {
    write("This is a saber with a blade of light.\n"+
          "The blade glows in a " + query_color() + " light.\n"+
          "There is something written on the handle.\n");
  }
  else {
    write("This seems to be the handle of a saber.\n"+
          "It has a button on it.\n"+
          "There is something written on it.\n");
  }
} 
 
init() {
::init();
  add_action("press","press");
  add_action("press","push");
}
 
press(str) {

  if(str!="button") return;

  if(environment()!=TP || !wielded || 
     TP->query_guild()!=GM->query_number("jedi")) {
    write("Nothing happens. How strange!\n");
    return 1;
  }
  if(!is_sword) {
    is_sword=1;
 
    write("As you press the button, a "+query_color()+" blade of light flashes"+
          " out of the handle.\nYou have to concentrate hard to keep the saber"+
          " under control.\n");
    say("Suddenly a "+query_color()+" blade of light flashes out of "+
         capitalize(wielded_by->query_real_name())+
        "'s simple handle.\nYou can hear a strange humming noise.\n");

    switching(1);
  }
  else {
    write("As you press the button the blade of light disappears.\n");
    say("The blade of light disappears.\n");
    switching(0);
  }
  return 1;
}

switching(arg) {
  if(arg) {
    set_hit_func(this_object());
    set_light(1);
    call_out("heart",5);
  }
  else {
    handle_reset();
    set_light(-1);
  }
}

un_wield() {
  if(is_sword) {
    notify("The blade of light dissapears.\n");
    handle_reset();
  }
  ::un_wield();
  return 1;
}
 
handle_reset() {
  is_sword=0;
  set_hit_func();
}
 
weapon_hit(attacker) {
  int dam;
  string atta;
  atta=attacker->query_name();
  dam=wielded_by->query_level();

  switch (random(9)) {
    case 0: notify(TP->query_name()+" swings "+TP->query_possessive()+ 
                   " lightsaber in a wide arc toward "+atta+".");
            break;
    case 1: notify(TP->query_name()+" thrusts at "+atta+" with "+
                   TP->query_possessive()+" lightsaber.");
            break;
    case 2: notify(TP->query_name()+"'s lightsaber throws off sparks as it "+
                   "slices through "+atta+"'s armour.");
            break;
    case 3: notify(atta+" screams as "+TP->query_name()+"'s lightsaber cuts "+
                   "through "+attacker->query_possessive()+" torso.");
            break;
    case 4: notify(TP->query_name()+"'s lightsaber hums as it pierces "+atta+ 
                   "'s form.");
            break;
    case 5: notify(TP->query_name()+" calmly dismembers "+atta+" with "+
                   TP->query_possessive()+" lightsaber.");
            break;
    case 6: notify(atta+" clutches at the horrible wounds dealt by "+
                   TP->query_name()+"'s lightsaber.");
            break;
    case 7: notify(TP->query_name()+"'s "+query_color()+" blade of light "+   
                   "slices through "+atta+"'s body.");
            break;
    case 8: notify(TP->query_name()+"'s lightsaber weaves under "+atta+"'s "+
                   "guard and pierces "+attacker->query_possessive()+" body.");
            break;
   }      
  notify("\n");
  return dam;
}
 
notify(str) {
   write(str);
   say(str);
}
 
get() {
  remove_call_out("fade_away");
  return 1;
}

drop() {
  ::drop();
  call_out("fade_away",30);
  return 0;
}

prevent_insert() {
  if(is_sword)
    write("You would ruin the bag.\n");
  return is_sword;
}

query_color() {
  int no;
  no=0;
  
  switch(TP->query_al_string()) {
    case "saintly": no++;
    case "good": no++;
    case "nice": no++;
    case "neutral": no++;
    case "nasty": no++;
    case "evil": no++;
    case "demonic": ;
    default: ;
  }
  
  return COLS[no];
}

fade_away() {
  tell_room(environment(),"The handle becomes indistinct and fades away.\n");
  destruct(this_object());
}

heart() {
  if(is_sword) {
    count++;
      if(wielded_by->query_spell_points()<20) {
        write("You lose your concentration.\nThe blade disapears.\n");
        switching(0);
      }
    call_out("heart",5);
  }
}

query_is_sword() { return is_sword; }
