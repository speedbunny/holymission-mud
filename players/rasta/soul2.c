#define SING_COST 5
#define DETAIL_COST 20
#define MAKE_BASE_COST 10
#define PRETITLE_COST 30
inherit "obj/armour";

object voorwerp,tp;
int getal,power,singing,songline,toggle;
string song;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("harp");
    set_short("A tiny silver harp");
    set_long("This is the item that you are proud of:\n"
           + "Your membership of the Guild of Bards.\n");
    set_ac(0);
    set_type("brooch");
    set_value(0);
    set_weight(0);
    power=0;
    set_info("The brooch Harp of the Guild of Bards.");
  }
  if(worn) {
    power=power+1;
    tell_object(tp,
      "The silver harp blinks, as it receives new power.\n");
  }
}

init() {
object all;
int i;
string name;

  ::init();
  add_action("detail","detail");
  add_action("make","make");
  add_action("maybe","maybe");
  add_action("spells","missile");
  add_action("spells","shock");
  add_action("spells","fireball");
  add_action("help","help");
  add_action("pretitle","pretitle");
  add_action("play","play");
  add_action("singing","sing");
  add_action("songs","songs");
  add_action("restore","restore");
  tp=this_player();
  all=all_inventory(tp);
  for(i=0; i<sizeof(all); i=i+1) {
    name=file_name(all[i]);
    name=explode(name,"#");
    if((name[0]=="players/cashimor/guild/soul")&&(all[i]!=this_object())) {
      destruct(all[i]);
      break;
    }
  }
}

songs() {
  say(this_player()->query_name()+" thinks for a moment.\n");
  "players/cashimor/guild/songroom"->query_list();
  return 1;
}

singing(str) {
string filenaam;
int i;

  if(singing) {
    write("But you are already singing!\n");
    return 1;
  }
  if(!str) {
    notify_fail("Sing what?\n");
    return 0;
  }
  filenaam="players/cashimor/guild/songroom"->query_song(str);
  if(!filenaam) {
    notify_fail("Unknown song.\n");
    return 0;
  }
  filenaam="/players/cashimor/songs/"+filenaam;
  if(!reduce_spell_points(SING_COST)) return 1;
  write("Ok.\n");
  i=this_player()->query_alignment()/10;
  if(i<0) {
    i=0;
  }
  this_player()->add_alignment(5+i);
  write("You start singing.\n");
  song=read_file(filenaam);
  song=explode(song,"\n");
  songline=0;
  singing=1;
  set_heart_beat(1);
  return 1;
}

heart_beat() {
  toggle=1-toggle;
  if(!toggle) {
    return;
  }
  sing_it(song[songline]);
  songline=songline+1;
  if(songline==sizeof(song)) {
    write("You stop singing.\n");
    set_heart_beat(0);
    singing=0;
  }
}

sing_it(str) {
string richtingen;
int i;

  tell_room(environment(tp),"[* Sung by "+tp->query_name()+" *]: "+str+"\n");
  richtingen=environment(tp)->query_dest_dir();
  if(!richtingen) return 1;
  i=1;
  while(i<sizeof(richtingen)) {
    tell_room(richtingen[i-1],"[* Distant song *]: "+str+"\n");
    do_echo(richtingen[i-1],str);
    i=i+2;
  }
}

restore() {
  if(!worn) {
    notify_fail("You must wear the harp to restore spell points!\n");
    return 0;
  }
  if(!power) {
    notify_fail("There's no power left in the brooch!\n");
    return 0;
  }
  this_player()->restore_spell_points(this_player()->query_level()*11);
  write("You feel more powerful now.\n");
  say(this_player()->query_name()
    + " touches a brooch and seems more powerful.\n");
  power=power-1;
  return 1;
}

do_echo(where,str) {
string richtingen;
int i;
object locatie;

  richtingen=where->query_dest_dir();
  if(!richtingen) return;
  i=1;
  while(i<sizeof(richtingen)) {
    locatie=find_object(richtingen[i-1]);
    if(locatie) {
      if(!present(tp,locatie)) {
        tell_room(richtingen[i-1],"[* Echo of song *]: "+str+"\n");
      }
    }
    i=i+2;
  }
  return;
}

play(str) {
  if(str!="harp") {
    notify_fail("Play what?\n");
    return 0;
  }
  if(!present(this_object(),this_player())) {
    notify_fail("Play what?\n");
    return 0;
  }
  notify_fail("You can't play this Harp! It's a brooch!\n");
  return 0;
}

help(str) {
  if((str=="fireball")||(str=="shock")||(str=="spell")) {
    str="missile";
  }
  if((str=="guild")||(str=="make")||(str=="maybe")||(str=="sing")||
     (str=="pretitle")||(str=="detail")||(str=="missile")||(str=="help")||
     (str=="restore")||(str=="songs")) {
    say(this_player()->query_name()+" is thinking of something...\n");
    cat("/players/cashimor/guild/helpdir/"+str);
    return 1;
  }
  return 0;
}

pretitle(str) {
  if(!str) {
    notify_fail("If you don't want a pretitle, use 'pretitle none'.\n");
    return 0;
  }
  if(this_player()->query_wizard()) return 0;
  if(!reduce_spell_points(PRETITLE_COST)) return 1;
  this_player()->set_pretitle(str);
  write("Pretitle set to: "+str+".\n");
  say(this_player()->query_name()+" patched "
    + this_player()->query_possessive()+" internals.\n");
  return 1;
}

spells() {
  write("I'm sorry, but you've to find other ways to do those things.\n");
  return 1;
}

maybe(str) {
  if(!str) return 0;
  say(this_player()->query_name()+" is enlightened.\n");
  write("Thank you!\n");
  log_file("cashimor.guild",this_player()->query_name()+":\n");
  log_file("cashimor.guild",str+"\n");
  return 1;
}

make(str) {
int ok;
string recept;

  if(!str) return 0;
  ok="players/cashimor/guild/room"->query_instrument(str);
  if(ok==0) return 0;
  recept="players/cashimor/guild/room"->query_needed(ok);
  if(!reduce_spell_points(MAKE_BASE_COST*sizeof(recept)/2)) return 1;
  for(getal=1; getal<sizeof(recept); getal=getal+1) {
    voorwerp=present(recept[getal],this_player());
    if(!voorwerp) {
      write("You don't have a "+recept[getal]+"!\n");
      ok=0;
      break;
    }
    if(first_inventory(voorwerp)) {
      write("There's something in "+lower_case(voorwerp->short())+"!\n");
      ok=0;
      break;
    }
    destruct(voorwerp);
  }
  if(ok) {
    voorwerp=clone_object("players/cashimor/instruments/"+str);
    voorwerp->set_creator(this_player()->query_real_name());
    if(transfer(voorwerp,this_player())) {
      move_object(voorwerp,environment(this_player()));
      write("You can't carry the instrument, so you drop it.\n");
    }
    write("You made "+lower_case(voorwerp->short())+".\n");
    say(this_player()->query_name()+" made "+lower_case(voorwerp->short())
      + ".\n");
  }
  return 1;
}

detail(str) {
string maker,filenaam;
int spell;

  if(!str) return 0;
  voorwerp=present(str,this_player());
  if(!voorwerp) {
    write("You don't have the "+str+" with you!\n");
    return 1;
  }
  if(!reduce_spell_points(DETAIL_COST)) return 1;
  write("Details about "+lower_case(voorwerp->short())+":\n");
  say(this_player()->query_name()+" takes a closer look at "
    + lower_case(voorwerp->short())+".\n");
  voorwerp->long(str);
  voorwerp->read(str);
  write("\n");
  if(voorwerp->query_name()) {
    write("It's name is: "+voorwerp->query_name()+".\n");
  }
  if(voorwerp->query_info()) {
    write("Some hidden information:\n"
        + voorwerp->query_info()+"\n");
  }    
  write("Checking if you can put it in something...\n");
  if(voorwerp->prevent_insert()) {
    write("Alas, no!\n");
  }
  else {
    write("Yes. It's possible.\n");
  }
  if(voorwerp->query_value()==0) {
    write("It's worth nothing.\n");
  }
  else {
    if(voorwerp->query_value()==1) {
      write("It has a value of one gold coin.\n");
    }
    else {
      write("It has a value of "+voorwerp->query_value()+" gold coins.\n");
    }
  }
  getal=voorwerp->query_weight();
  switch(getal) {
    case 0: write("It's weightless.\n"); break;
    case 1: write("It weighs almost nothing.\n"); break;
    case 2: write("It's a rather light object.\n"); break;
    case 3: write("It has a good weight.\n"); break;
    case 4: write("You could call it heavy.\n"); break;
    case 5: write("It certainly is heavy.\n"); break;
    case 6: write("You could call it very heavy.\n"); break;
    case 7: write("It feels very heavy.\n"); break;
    case 8: write("It is very heavy.\n"); break;
    case 9: write("It is VERY heavy.\n"); break;
    case 10: write("You sigh under the weight of it.\n"); break;
    case 11: write("It feels extremely heavy.\n"); break;
    case 12: write("It is extremely heavy.\n"); break;
    case 13: write("It is EXTREMELY heavy.\n"); break;
    case 14: write("Why are you carrying this weight with you?\n"); break;
    case 15: write("Put it down. It's too heavy.\n"); break;
  }
  if(getal>15) write("How did you ever lift it?\n");
  if(getal<0) write("It's lighter than nothing.\n");
  if(voorwerp->id("armour")) {
    write("This is an armour.\n");
    if(voorwerp->query_worn()) {
      getal=voorwerp->armour_class();
      switch(getal) {
        case 0: write ("It doesn't protect you.\n"); break;
        case 1: write("It gives a little protection.\n"); break;
        case 2: write("It gives normal protection.\n"); break;
        case 3: write("It gives good protection.\n"); break;
        case 4: write("It gives very good protection.\n"); break;
      } 
      if(getal>4) write("It gives too good protection.\n");
    }
    write("It has a size of: "
        + voorwerp->query_size_name(voorwerp->query_size())+".\n");
  }
  if(voorwerp->query_type()) {
    write("It's type is: "+voorwerp->query_type()+".\n");
  }
  if(voorwerp->can_put_and_get()) write("You can put things in it.\n");
  if(voorwerp->query_max_weight()) {
    getal=voorwerp->query_max_weight();
    switch(getal) {
      case 1: write("It can't contain more than one thing.\n"); break;
      case 2: write("You can put a light item in it.\n"); break;
      case 3: write("You can put a normal item in it.\n"); break;
      case 4: write("It may be able to contain two items.\n"); break;
      case 5: write("It should be able to contain two items.\n"); break;
      case 6: write("It may be able to contain three things.\n"); break;
      case 7: write("It should be able to contain three things.\n"); break;
      case 8: write("It can probably hold more than three things.\n"); break;
      case 9: write("It can probably hold more than three items.\n"); break;
      case 10: write("It may be able to contain four items.\n"); break;
      case 11: write("It should be able to contain four items.\n"); break;
      case 12: write("It can be filled with possibly five items.\n"); break;
      case 13: write("It should be able to contain five items.\n"); break;
      case 14: write("It can contain many items.\n"); break;
      case 15: write("It should be able to hold many items.\n"); break;
    }
    if(getal>15) write("It probably can contain more than you carry.\n");
  }
  if(voorwerp->min_cost()) write("You can probably eat or drink it.\n");
  if(voorwerp->id("remains")) write("Why have you taken this?\n");
  if(voorwerp->query_code()) {
    if((voorwerp->query_code())=="zap") { 
      write("This key should fit all doors.\n");
    }
    write("It has a code of: "+voorwerp->query_code()+".\n");
  }
  if(voorwerp->query_auto_load()) write("It will stick with you forever.\n");
  if(voorwerp->weapon_class()) {
    write("This is a weapon.\n");
    getal=voorwerp->weapon_class();
    switch(getal) {
      case 1: write("You can better use your hands...\n"); break;
      case 2: write("It's VERY blunt.\n"); break;
      case 3: write("Maybe as strong as your bare hands.\n"); break;
      case 4: write("Search another weapon, will you?\n"); break;
      case 5: write("This looks as strong as a knife.\n"); break;
      case 6: write("Just a little bit stronger than a knife.\n"); break;
      case 7: write("This is as strong as a curved knife.\n"); break;
      case 8: write("Just a bit better than a curved knife.\n"); break;
      case 9: write("As strong as a hand axe.\n"); break;
      case 10: write("In the neighboorhood of a short sword.\n"); break;
      case 11: write("Better than a hand axe.\n"); break;
      case 12: write("Better than a short sword.\n"); break;
      case 13: write("That begins to become dangerous.\n"); break;
      case 14: write("Yes, this is good for the beginning.\n"); break;
      case 15: write("This feels like a fine weapon.\n"); break;
      case 16: write("This feels like a very fine weapon.\n"); break;
      case 17: write("This feels like an extremely fine weapon.\n"); break;
      case 18: write("It's close to the ultimate weapon.\n"); break;
      case 19: write("You feel almost invincible.\n"); break;
      case 20: write("The ultimate weapon!\n"); break;
    }
    if(getal>20) write("This weapon is too strong.\n");
  }
  maker=voorwerp->query_creator();
  if(!maker) maker=creator(voorwerp);
  if(maker) write("It was created by: "+capitalize(maker)+".\n");
  if(voorwerp->id("instrument")) {
    write("It's an instrument.\n");
    spell=voorwerp->query_spell(1);
    if(spell) {
      write("There's a spell stored in the instrument.\n");
      write("You need to be level "+spell+" to use it.\n");
      write("This spell needs "+voorwerp->query_spell()
          + " spellpoints to execute properly.\n");
    }
  }
  filenaam=explode(file_name(voorwerp),"#");
  filenaam="/"+filenaam[0]+".c";
  getal=file_size(filenaam);
  if(!creator(voorwerp)) getal=0;
  if(getal<1024) {
    write("It's a rather standard item.\n");
  }
  else {
    if(getal<2048) {
      write("It could have interesting abilities.\n");
    }
    else {
      if(getal<4096) {
        write("Maybe it's more than it seems.\n");
      }
      else {
        write("A lot of work has gone into this item.\n");
      }
    }
  }
  if(voorwerp->extra_look()) {
    write("It causes: "+voorwerp->extra_look()+".\n");
  }
  return 1;
}

reduce_spell_points(number) {
  if(!worn) {
    write("You must wear the harp to be able to do that!\n");
    return 0;
  }
  if(this_player()->query_alignment()<0) {
    write("You have to be nice or better!\n");
    return 0;
  }
  if(this_player()->query_spell_points()<number) {
    write("Too low on power!\n");
    return 0;
  }
  this_player()->restore_spell_points(-number);
  return 1;
}

extra_look() {
  if(!worn) return 0;
  return "This is a charismatic member of the Guild of Bards";
}

drop(silently) {
  return 1;
}

prevent_insert() {
  return 1;
}
