inherit "obj/armour";

/* ************************************************************************** */
/*              Amulet of Wizardhood, by Bubbs. Version 3.0.5                 */
/* ************************************************************************** */

object locale;
string ex_lk;
int alarm_set, hour, minute, time_diff;

/* ************************************************************************** */
/*             These functions set up the object ready for use.               */
/* ************************************************************************** */

check_wizard() { return (this_player()->query_level() > 33); }

drop() { return 1; }

extra_look() { return ex_lk; }

get() { return check_wizard(); }

query_auto_load() { return "players/silas/tools/amulet:"; }

init() {
  ::init();
  if (!check_wizard()) return 0;
  if (!worn) {
    locale = this_player();
    worn = 1;
    }
  add_action("alarm_set",    "alarm");
  add_action("call",         "call");
  add_action("callout",      "callout");
  add_action("clomo",        "clomo");
  add_action("clon",         "clon");
  add_action("desc",         "desc");
  add_action("eall",         "eall");
  add_action("ensoul",       "ensoul");
  add_action("eep_pose",     "epo");
  add_action("exec",         "exec");
  add_action("fear",         "fear");
  add_action("f_name",       "fname");
  add_action("help",         "help");
  add_action("in",           "in");
  add_action("light",        "light");
  add_action("list_inv",     "linv");
  add_action("long_disp",    "long");
  add_action("make",         "make");
  add_action("omo",          "omo");
  add_action("oto",          "oto");
  add_action("pose",         "pose");
  add_action("secho",        "secho");
  add_action("select_echo",  "selec");
  add_action("select_shout", "selsh");
  add_action("sgo",          "sgo");
  add_action("snigger",      "snigger");
  add_action("stat_object",  "stat");
  add_action("stop_fight",   "stopfight");
  add_action("tell_log",     "telllog");
  add_action("time_disp",    "ti");
  add_action("wipe",         "wipe");
  add_action("zone_time",    "zone");
  }

reset(arg) {
  ::reset(arg);
  if (arg) return 0;
  set_name("amulet");
  set_short("Amulet of Wizardhood");
  set_long("The Amulet of Wizardhood is an arcane item, forged when the " +
	"current\nuniverse was not fully evolved. It is said to bestow many gifts "
	+ "onto its\nwearer, but mere mortals are thought not to be able to control"
	+ " its powers.\n");
  set_type("amulet");
  set_weight(1);
  set_value(0);
  }

/* ************************************************************************** */
/*         These following functions are used by the command functions.       */
/* ************************************************************************** */

alarm(owner) {
  write("The alarm on your watch has gone off!\n");
  alarm_set = 0;
  return 1;
  }

evaluate_path(str) {
  string strarr, tmp1, tmp2;
  int index;
  str = this_player()->query_path() + "/" + str;
  strarr = explode(str, "/");
  while(sscanf(str, "%s/../%s", tmp1, tmp2)) {
    index = sizeof(explode(tmp1, "/"));
    sscanf(tmp1, "%s/"+strarr[index-1], tmp1);
    str = tmp1 + "/" + tmp2;
    }
  return str;
  }

get_ob(tname, env) {
  object ob, targ;
  string temp;
  int posit;
  if (sscanf(tname, "%s%%d", temp, posit) == 2) tname = temp;
  else posit = 1;
  if (sscanf(tname, "ENV:%s", temp) == 1 || sscanf(tname, "env:%s", temp) == 1
   || sscanf(tname, "<<%s", temp) == 1) {
    if (env) return env;
    else return environment(get_ob(temp));
    }
  if (!env) {
    if (tname == "me") targ = locale;
    else if (tname == "this") targ = this_object();
    else if (tname == "here") targ = environment(locale);
    else if (find_living(tname)) targ = find_living(tname);
    else if (find_object(locale->query_path() + "/" + tname))
     targ = find_object(locale->query_path() + "/" + tname);
    else if (find_object("room/" + tname)) targ = find_object("room/" + tname);
    else if (find_object(tname)) targ = find_object(tname);
    else if (present(tname, this_player()))
     targ = get_ob(tname + "%" + posit, locale);
    else if (present(tname, environment(locale)))
     targ = get_ob(tname + "%" + posit, environment(locale));
    return targ;
    }
  ob = first_inventory(env);
  while(ob && posit) {
    if (ob->id(tname)) {
      targ = ob;
      posit = posit - 1;
      }
    ob = next_inventory(ob);
    }
  return targ;
  }

locate_ob(str) {
  string list;
  int num;
  object targ;
  if (!str) return 0;
  list = explode(str, ">>");
  num = sizeof(list);
  while(num) {
    targ = get_ob(list[num - 1], targ);
    num = num - 1;
    }
  return targ;
  }

mod_str(str) {
  string temp1, temp2;
  str = subst(str, "\\b", "\b");
  str = subst(str, "\\f", "\f");
  str = subst(str, "\\r", "\r");
  str = subst(str, "\\n", "\n");
  str = subst(str, "\\t", "\t");
  return str;
  }

show_alarm(hour,minute) {
  if (!hour) write("00");
  else write(hour);
  write(":");
  if (minute < 10) write("0");
  write(minute + "\n");
  return 1;
  }

show_info(ob, func, label) {
  if (call_other(ob, func))
   write(label + "\t:  " + call_other(ob, func) + "\n");
  }

sshout(str, ob) {
  object players;
  int num;
  players = users();
  num = sizeof(players);
  while(num) {
    if (players[num-1] != this_player() && players[num-1] != ob)
     tell_object(players[num-1], str);
    num--;
    }
  return 1;
  }

subst(str, with, what) {
  int num, len1, len2;
  string new_str;
  len1 = strlen(str);
  len2 = strlen(with);
  new_str = "";
  while(num != len1) {
    if (extract(str, num, num+len2-1) == with) {
      new_str = new_str + what;
      num += len2;
      }
    else {
      new_str = new_str + extract(str, num, num);
      num ++;
      }
    }
  return new_str;
  }

show_var_type(var) {
  if (intp(var)) tell_object(locale, "integer " + var + "\n");
  else if (stringp(var)) tell_object(locale, "string \"" + var + "\"\n");
  else if (objectp(var)) tell_object(locale, "object " + file_name(var) + "\n");
  else if (pointerp(var)) {
    int index, size;
    size = sizeof(var);
    tell_object(locale, "array size " + size + "\n");
    while(index < size) {
      tell_object(locale, "[" + index + "] ");
      show_var_type(var[index]);
      index++;
      }
    }
  }

version() { return "Amulet of Wizardhood version 3.0.5"; }

/* ************************************************************************** */
/*           The following functions are the command functions.               */
/* ************************************************************************** */

alarm_set(str) {
  int num, dat, sec, year, phour, pminute;
  string name, dow, mon;
  if (!str) {
    if (!alarm_set) {
      write("You haven't set it!\n");
      return 1;
      }
    write("The alarm is due to go off at ");
    show_alarm(hour, minute);
    return 1;
    }
  if (str == "off") {
    if (remove_call_out("alarm") == -1) {
      write("You hadn't set it!\n");
      return 1;
      }
    write("You turn the alarm off.\n");
    alarm_set = 0;
    return 1;
    }
  if (alarm_set) {
    write("It's already been set, for ");
    show_alarm(hour, minute);
    return 1;
    }
  if (sscanf(str, "%d:%d", hour, minute) != 2) {
    write("Bad time.\n");
    return 1;
    }
  sscanf(ctime(time() + time_diff), "%s %s %d %d:%d:%d %d",
   dow, mon, dat, phour, pminute, sec, year);
  num = (3600 * (hour - phour)) + (60 * (minute - pminute)) - sec;
  if (num < 0) num += 86400;
  call_out("alarm", num, this_player());
  write("Set alarm for ");
  show_alarm(hour, minute);
  alarm_set = 1;
  return 1;
  }

call(str) {
  string tname, func, arg, temp1, temp2;
  object target;
  int flag, result;
  if (!str) return 0;
  if (sscanf(str, "%s %s %d", tname, func, arg) == 3) flag = 1;
  else if (sscanf(str, "%s %s %s", tname, func, arg) != 3) {
    if (sscanf(str, "%s %s", tname, func) == 2) flag = 0;
    }
  target = locate_ob(tname);
  if (!target) return 0;
  if (arg && stringp(arg)) {
    arg = mod_str(arg);
    if (stringp(arg) && extract(arg, 0,1) == "$$") sscanf(arg, "$$%s", arg);
    if (stringp(arg) && extract(arg, 0,1) == "##") {
      sscanf(arg, "##%s", temp1);
      arg = locate_ob(temp1);
      if (!arg) return 0;
      }
    }
  result = call_other(target, func, arg);
  tell_object(locale, "Returned: ");
  show_var_type(result);
  return 1;
  }

callout(str) {
  int delay;
  string line, ob, func, arg;
  if (!str || sscanf(str, "%d %s %s", delay, ob, func) < 3) return 0;
  line = ob + " " + func;
  sscanf(func, "%s %s", func, arg);
  call_out("call", delay, line);
  write("Function " + func + " in " + ob + " called out with ");
  if (arg && arg != "0") write("argument " + arg + " and ");
  write("delay " + delay + ".\n");
  return 1;
  }

clomo(str) {
  string name, fname;
  object targ, ob;
  if (!str || sscanf(str, "%s %s", fname, name) != 2) return 0;
  targ = locate_ob(name);
  ob = locate_ob(fname);
  fname = file_name(ob);
  if (!targ || !ob) return 0;
  ob = clone_object(fname);
  move_object(ob, targ);
  return 1;
  }

clon(str) {
  object temp;
  temp = clone_object(str);
  if (!temp) return 0;
  move_object(temp, this_player());
  return 1;
  }

desc(str) {
  if (str) ex_lk = mod_str(str);
  if (str == "\"\"") {
    ex_lk = 0;
    write("Description set to null.\n");
    }
  else write("Desc: " + ex_lk + ".\n");
  return 1;
  }

eall(str) {
  sshout(mod_str(str) + "\n");
  return 1;
  }

eep_pose() {
  sshout("A load of eeps explode into the sky, squealing: *E*E*P*!*.\n");
  write("Ok.\n");
  return 1;
  }

ensoul(str) {
  object targ;
  targ = locate_ob(str);
  if (!targ || !living(targ)) return 0;
  move_object(clone_object("obj/soul"), targ);
  return 1;
  }

exec(str) {
  string tname, comm;
  object targ;
  if (sscanf(str, "%s %s", tname, comm) != 2) return 0;
  targ = locate_ob(tname);
  if (!targ) return 0;
  command(mod_str(comm), targ);
  return 1;
  }

fear(str) {
  if (!find_living(str)) return 0;
  write("You make a horrid face at " + capitalize(str) + ".\n");
  say(this_player()->query_name() + " makes a horrid face at " +
   capitalize(str) + ".\n", find_living(str));
  tell_object(find_living(str),this_player()->query_name() +
   " makes a horrid face at you.\n");
  find_living(str)->run_away();
  return 1;
  }

f_name(str) {
  object targ;
  if (!str) return 0;
  targ = locate_ob(str);
  if (!targ) return 0;
  write(file_name(targ) + "\n");
  return 1;
  }

help(topic) {
  if (!topic) return 0;
  return call_other("players/silas/tools/amulet_help", topic);
  }

in(str) {
  string place, comm;
  object target, env;
  if (!str || sscanf(str, "%s %s", place, comm) != 2) return 0;
  target = locate_ob(place);
  if (!target) return 0;
  env = environment(this_player());
  move_object(this_player(), target);
  command(mod_str(comm), this_player());
  move_object(this_player(), env);
  return 1;
  }

light(str) {
  int num;
  if (!str || sscanf(str,"%d",num) != 1) num = 0;
  write("The light here is ");
  if (num) write("now");
  write(set_light(num) + ".\n");
  return 1;
  }

list_inv(str) {
  object targ, ob;
  targ = locate_ob(str);
  if (!targ) return 0;
  write("Contents of: " + file_name(targ) + "\n");
  ob = first_inventory(targ);
  while(ob) {
    write(ob->short() + "\t" + file_name(ob) + "\n");
    ob = next_inventory(ob);
    }
  return 1;
  }

long_disp(str) { return call(str + " long"); }

make(str) {
  object thing;
  if (str != "treasure" && str != "weapon" && str != "armour" &&
   str != "light" || str != "monster") return 0;
  else if (str == "treasure") thing = clone_object("obj/treasure");
  else if (str ==   "weapon") thing = clone_object("obj/weapon");
  else if (str ==   "armour") thing = clone_object("obj/armour");
  else if (str ==    "light") thing = clone_object("obj/light");
  else if (str ==  "monster") thing = clone_object("obj/monster");
  if (str == "treasure") thing->set_id(str);
  else thing->set_name(str);
  move_object(thing, this_player());
  return 1;
  }

omo(str) {
  object targ1, targ2;
  string tname1, tname2;
  if (!str || sscanf(str, "%s %s", tname1, tname2) != 2) return 0;
  targ1 = locate_ob(tname1);
  targ2 = locate_ob(tname2);
  if (!targ1 || !targ2) return 0;
  move_object(targ1, targ2);
  return 1;
  }

oto(str) {
  string tname1, tname2;
  object targ1, targ2;
  int trans;
  if (!str || sscanf(str, "%s %s", tname1, tname2) != 2) return 0;
  targ1 = locate_ob(tname1);
  targ2 = locate_ob(tname2);
  if (!targ1 || !targ2) return 0;
  trans = transfer(targ1, targ2);
  if (trans == 0) write("Ok.\n");
  else if (trans == 1) write(tname1 + " is too heavy for " + tname2 + ".\n");
  else if (trans == 2) write(tname1 + " cannot be dropped.\n");
  else if (trans == 3) write(tname1 + " cannot be taken from its container.\n");
  else if (trans == 4) write(tname1 + " cannot be inserted into containers.\n");
  else if (trans == 5) write(tname2 + " isn't a container.\n");
  else if (trans == 6) write(tname1 + " cannot be picked up.\n");
  return 1;
  }

pose(str) {
  int count, length;
  string char, new_str;
  if (!str) return 0;
  length = strlen(mod_str(str));
  count = 0;
  new_str = "";
  while(count < length) {
    char = capitalize(extract(str, count, count));
    new_str += "*" + char;
    count++;
    }
  new_str += "*";
  write("You send a ball of fire into the sky.\n");
  write("(" + new_str + ")\n");
  say(this_player()->query_name() + " makes a magical gesture.\n");
  sshout("A ball of fire explodes in the sky, spelling: " + new_str + ".\n");
  return 1;
  }

secho(str) {
  say(str + "\n");
  write("You echo: " + str + "\n");
  return 1;
  }

select_echo(str) {
  string name, mesg;
  object except;
  if (!str || sscanf(str, "%s %s", name, mesg) != 2) return 0;
  except = find_living(name);
  if (!except) return 0;
  say(mod_str(mesg) + "\n", except);
  return 1;
  }

select_shout(str) {
  string name, mesg;
  object except;
  if (!str || sscanf(str, "%s %s", name, mesg) != 2) return 0;
  except = find_player(name);
  if (!except) return 0;
  sshout(mod_str(mesg) + "\n", except);
  return 1;
  }

sgo(str) {
  object targ;
  if (str == "home") {
    move_object(this_player(), "players/" + this_player()->query_name() +
     "/workroom");
    return 1;
    }
  targ = locate_ob(str);
  if (!targ) return 0;
  move_object(this_player(), targ);
  if (living(environment(this_player()))) move_object(this_player(),
   environment(environment(this_player())));
  return 1;
  }

snigger() {
  say(this_player()->query_name() + " sniggers manically.\n");
  write("You snigger manically.\n");
  return 1;
  }

stat_object(str) {
  object target;
  target = locate_ob(str);
  if (!target) return 0;
  write(file_name(target) + "\n");
  if (living(target)) {
    target->show_stats();
    return 1;
    }
  if (creator(target)) write("Creator\t:  " + capitalize(creator(target)) +
   "\n");
  show_info(target, "query_name", "Name");
  show_info(target, "short", "Short");
  target->long();
  write("Weight\t:  " + target->query_weight() + "\n");
  write("Value\t:  " + target->query_value() + "\n");
  show_info(target, "get", "Get");
  if (!target->armour_class() && !target->weapon_class())
   show_info(target, "drop", "Drop");
  show_info(target, "armour_class", "AC");
  show_info(target, "query_type", "Type");
  show_info(target, "weapon_class", "WC");
  show_info(target, "extra_look", "Extra look");
  show_info(target, "query_worn", "Worn");
  show_info(target, "query_wielded", "Wielded");
  show_info(target, "can_put_and_get", "Container");
  show_info(target, "add_weight", "Bag");
  return 1;
  }

stop_fight(str) {
  object target, ob;
  if (!str) str = "here";
  target = locate_ob(str);
  if (!target) return 0;
  ob = first_inventory(target);
  while(ob) {
    if (living(ob)) {
      ob->stop_fight();
      ob->stop_fight();
      ob->stop_hunter();
      }
    ob = next_inventory(ob);
    }
  return 1;
  }

tell_log(str) {
  string who, mesg;
  if (!str) return 0;
  if (sscanf(str, "%s %s", who, mesg) != 2) mesg = "";
  if (who == "me") who = this_player()->query_real_name();
  log_file(who, mod_str(mesg) + "\n");
  return 1;
  }

time_disp() {
  write("The time is " + ctime(time() + time_diff) + "\n");
  return 1;
  }

wipe(str) {
  object targ;
  if (!str) return 0;
  if (str == "all") str = "all>>me";
  if (sscanf(str, "all>>%s", str) == 1) {
    object ob, nextob;
    targ = locate_ob(str);
    if (!targ) return 0;
    ob = first_inventory(targ);
    while(ob) {
      nextob = next_inventory(ob);
      if (!ob->id("soul") && ob != this_object()) destruct(ob);
      ob = nextob;
      }
    return 1;
    }
  targ = locate_ob(str);
  if (!targ) return 0;
  destruct(targ);
  return 1;
  }

zone_time(str) {
  int h, m, diff_h, diff_m;
  diff_h = time_diff / 3600;
  diff_m = time_diff - (3600 * diff_h);
  if (!str) {
    write("Time difference is currently " + diff_h + ":");
    if (diff_m < 10) write("0");
    write(diff_m + ".\n");
    return 1;
    }
  if (sscanf(str, "%d:%d", h, m) != 2) {
    write("Bad time difference.\n");
	 write("Format should be: hh:mm\n");
	 return 1;
    }
  time_diff = (3600 * h) + (60 * m);
  write("Time difference is now " + h + ":");
  if (m < 10) write("0");
  write(m + ".\n");
  return 1;
  }
