inherit "obj/thing";

string seccom,yousnd,theysnd,maker;
int spell,level,hidden,gd,cpag,local_weight;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_can_get(1);
    set_weight(1);
    set_value(50);
    set_name("instrument");
    gd="players/cashimor/guild/room"->query_guild();
  }
}

init() {
  ::init();
  add_action("play_it","play");
  if(seccom) {
    add_action("play_it",seccom);
  }
  add_action("hide","hide");
  add_action("search","search");
}

play_it(str) {
  if(!str) return 0;
  if(!id(str)) return 0;
  if((!present(this_object(),this_player()))&&(can_get)) return 0;
  if(first_inventory(this_object())) {
    write("You play a false note.\n");
    say(this_player()->query_name()+" makes a terrible noise with "
      + lower_case(short())+".\n");
    return 1;
  }
  write(yousnd);
  say(this_player()->query_name()+" "+theysnd);
  if(spell) {
    preprocess_spell();
  }
  environment(this_player())->music_done(this_object());
  return 1;
}

search(str) {
  if(!str) return 0;
  if(!id(str)) return 0;
  if(!hidden) {
    write("But it wasn't hidden!\n");
    return 1;
  }
  say(this_player()->query_name()+" discovers something.\n");
  write("You find an instrument.\n");
  hidden=0;
  return 1;
}

hide(str) {
  if(!str) return 0;
  if(!id(str)) return 0;
  if(hidden) {
    write("But it is already hidden!\n");
    return 1;
  }
  say(this_player()->query_name()+" hides something.\n");
  write("You have hidden the instrument.\n");
  hidden=1;
  return 1;
}

short() {
  if(hidden) return 0;
  return ::short();
}

/* USERDOC:
set_2nd_com
Format: set_2nd_com(s)
Example: set_2nd_com("bang")
See also: query_2nd_com
This function makes 's' a command to be used instead of 'play' (play will
still be defined. So now you can <s> instrument, as well as play instrument.
*/
set_2nd_com(s) {
  seccom=s;
}

/* USERDOC:
query_2nd_com
Format: s=query_2nd_com()
See also: set_2nd_com
This function reads the second command set for the instrument.
*/
query_2nd_com() {
  return seccom;
}

/* USERDOC:
set_write_snd
Format: set_write_snd(s)
Example: set_write_snd("You play the horn.\n")
See also: query_write_snd
This function sets the message displayed on screen if you play the instrument.
*/
set_write_snd(s) {
  yousnd=s;
}

/* USERDOC:
query_write_snd
Format: s=query_write_snd()
See also: set_write_snd
This function reads the write sound set for the instrument.
*/
query_write_snd() {
  return yousnd;
}

/* USERDOC:
set_say_snd
Format: set_say_snd(s)
Example: set_say_snd("plays a horn.\n");
See also: query_say_snd
This function sets the message displayed on the screen of others (prepended
with the name of this_player()).
*/
set_say_snd(s) {
  theysnd=s;
}

/* USERDOC:
query_say_snd
Format: s=query_say_snd()
See also: set_say_snd
This function reads the say sound set for the instrument.
*/
query_say_snd() {
  return theysnd;
}

set_spell(i,i2) {
  spell=i;
  level=i2;
}

query_spell(i) {
  if(!i) return spell;
  return level;
}

id(str) {
  return (::id(str))||(str=="instrument");
}

preprocess_spell() {
  if(this_player()->query_guild()!=gd) return;
  if(this_player()->query_level()<level) return;
  if(!reduce_spell_points()) return;
  do_spell();
}

do_spell() {
object contents;
int number;

  contents=all_inventory(environment(this_player()));
  for(number=0; number<sizeof(contents); number=number+1) {
    if(living(contents[number])) {
      if(!contents[number]->query_no_ears()) {
        spell_target(contents[number]);
      }
    }
  }
}

reduce_spell_points() {
  if(this_player()->query_spell_points()<spell) return 0;
  this_player()->restore_spell_points(-spell);
  return 1;
}

can_put_and_get() {
  return cpag;
}

set_cpag(s) {
  cpag=s;
}

add_weight(w) {
  if(!cpag) return 0;
  if(local_weight+w>weight) return 0;
  local_weight=local_weight+w;
  return 1;
}

/* USERDOC:
query_value
Format: i=query_value()
This function queries the value of the instrument, which can be set with
set_value(i).
*/
query_value() {
  hidden=0;
  return ::query_value();
}

/* USERDOC:
query_creator
Format: s=query_creator()
See also: set_creator
This reads the set creator for the item. If it's 0, use the creator(o) efun.
Please use query_creator() before creator() if the information is meant for
the players.
*/
query_creator() {
  return maker;
}

/* USERDOC:
set_creator
Format: set_creator(s)
Example: set_creator("cashimor")
See also: query_creator
This sets the 'creator' of the instrument to s. The creator is the one who made
the instrument, not the one who made the file. This can be used to substitute
the creator(o) efun, if it's programmed elsewhere (at this moment only in two
places).
*/
set_creator(s) {
  maker=s;
}
