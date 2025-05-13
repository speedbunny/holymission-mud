//
//  A nice generic file for inheriting to create wands  =)
//  Created by Ted  [date unknown]
//  Updated by Elemental Tamina 08-05-95
//

#include "/players/tamina/defs.h"

object ob;
string info, name, spell_type;
string short_desc, long_desc, alias;
string spell_mess1, spell_mess2;
string do_cmd, alt_name;
int value, weight, charges, spell_dam, kind;
status used;
mixed *elem;

void reset(int arg) 
{
  if (arg) return 0;
  charges = 0;
  spell_dam = 0;
}

void init() 
{
  add_action("do_spell"); add_verb(do_cmd);
}

int id(string str) 
{
  return (str == name || str == alias || str == alt_name || str == "wand");
}

int query_charges() 
{ 
  return charges; 
}

void query_info()
{ 
  write("Charges: "+charges+",\n"+
        "   Spell type: "+spell_type+",\n"+
        "      Spell damage: 1-"+spell_dam+",\n"+
        "         Command: "+do_cmd+".\n");
}

int query_kind()     { return kind; }
string query_name()  { return name; }
string query_alias() { return alias; }
int query_value()    { return value; }
int query_weight()   { return weight; }
void long()          { write(long_desc); }
string query_long()  { return long_desc; }
string query_short() { return short_desc; }
string short()       { return short_desc; }
string query_type()  { return spell_type; }

set_name(n)          { name = n; set_short(n); }
set_alias(a)         { alias = a; }
set_alt_name(alt)    { alt_name = alt; }
set_short(s)         { short_desc = s; long_desc = s+"\n"; }
set_long(l)          { long_desc = l; }
set_kind(k)          { kind = k; }
set_value(v)         { value = v; }
set_weight(w)        { weight = w; }
set_spell_mess1(m1)  { spell_mess1 = m1; }
set_spell_mess2(m2)  { spell_mess2 = m2; }
set_spell_dam(dam)   { spell_dam =  dam; }
set_spell_type(t)    { spell_type = t; }
set_charges(c)       { charges = c; }
set_command(cmd)     { do_cmd = cmd; }
set_elem(el)         { el = ({}); }

int do_spell(string str) 
{
  if (used) 
  {
    write("Your wand is not ready to attack again yet.\n");
    return 1;
  }
  if (!str)
    ob = this_player()->query_attack();
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) 
  {
    write("At whom?\n");
    return 1;
  }
  if (charges <= 0) 
  {
    write(short_desc+" vibrates slightly, but nothing happens.\n");
    say(this_player()->query_name()+" fiddles with "+short_desc+", but nothing happens.\n");
    return 1;
  }
  charges -= 1;
  if (ob->query_npc())
    ob->attack_object(this_player());
  used = 1;
  call_out("fire", 1);
  return 1;
}

fire()
{
  if(environment(this_player())->query_property("no_fight"))
  {
      write("You can't do that here.\n");
      say(this_player()->query_real_name()+" tried to attack here.\n");
      return;
  }
  tell_object(ob, "You are hit by a "+spell_type+"!\n");
  write(spell_mess2+"\n");
  say(this_player()->query_name()+" activates "+short_desc+".\n");
  say(spell_mess1+"\n");

  ob->hit_player(spell_dam, kind, elem);
  call_out("ready", 1);
  return 1;
}

ready() { used = 0; return 1; }

int get()  { return 1; }
int drop() { return 0; }
