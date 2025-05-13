#include "lw.h"
#include "/players/matt/test/soul/feelings.h"

string *feelings_list;

int id(string str) {
  return str == "mastersoul";
}

void reset(int arg) {
  if(arg) return;
  feelings_list = m_indices(feelings_map);
}

void do_feeling(string verb, string *args) {
  int adv_num;
  string *msg_list;
  string adverb;
  object *others;
  object target;

  msg_list = feelings_map[verb];
  switch(sizeof(args)) {
  case 0:
    write(lw(parse_it(msg_list, 0, "", 0)));
    say(lw(parse_it(msg_list, 1, "", 0)));
    return;
  case 1:
    adverb = find_adverb(args[1], previous_object());
    if(!adverb || (adverb == "")) {
      if(msg_list[5] == "" || !(target = present(arg_list[1], ENV(TP))))
	write("Adverb '" + arg_list[1] + "' not found.\n");
      else {
	write(lw(parse_it(msg_list, 2, "", target)));
	say(lw(parse_it(msg_list, 3, "", target)), target);
	tell_object(target, lw(parse_it(msg_list, 4, "", target)));
      }
    }
    else {
      write(lw(parse_it(msg_list, 0, adverb, 0)));
      say(lw(parse_it(msg_list, 1, adverb, 0)));
    }
    break;
  case 2:
    if(msg_list[5] == "")
      write("You can't do that to " + capitalize(args[1]) + ".\n");
    else if(!(target = present(args[1], ENV(TP))))
      write(capitalize(args[1] + " is not here.\n"));
    else {
      adverb = find_adverb(args[2], previous_object());
      if(!adverb || adverb == "")
	write("Adverb " + args[2] + " not found.\n");
      else {
	write(lw(parse_it(msg_list, 2, adverb, target)));
	say(lw(parse_it(msg_list, 3, adverb, target)), target);
	tell_object(target, lw(parse_it(msg_list, 4, adverb, target)));
      }
    }
    break;
  }
}

string parse_it(string *list, int num, string adv, object targ) {
  string str1;
  string str2;

  switch(num) {
  case 0:
    return implode(explode(list[0], "<ADV>"), adv) + "\n";
  case 1:
    str1 = implode(explode(list[1], "<ADV>"), adv);
    str2 = implode(explode(str1, "<ME>"), TP->SNAME);
    str1 = implode(explode(str2, "<MPOS>"), TP->query_possessive());
    str2 = implode(explode(str1, "<MPRO>"), TP->query_pronoun());
    str1 = implode(explode(str1, "<MOBJ>"), TP->query_objective());
    return str1 + "\n";
  case 2:
    str1 = implode(explode(list[2], "<ADV>"), adv);
    str2 = implode(explode(str1, "<TARG>"), targ->SNAME);
    str1 = implode(explode(str2, "<TPOS>"), targ->query_possessive());
    str2 = implode(explode(str1, "<TPRO>"), targ->query_pronoun());
    str1 = implode(explode(str2, "<TOBJ>"), targ->query_objective());
    return str1 + "\n";
  case 3:
    str1 = implode(explode(list[3], "<ADV>"), adv);
    str2 = implode(explode(str1, "<ME>"), TP->SNAME);
    str1 = implode(explode(str2, "<MPOS>"), TP->query_possessive());
    str2 = implode(explode(str1, "<MPRO>"), TP->query_pronoun());
    str1 = implode(explode(str1, "<MOBJ>"), TP->query_objective());
    str2 = implode(explode(str1, "<TARG>"), targ->SNAME);
    str1 = implode(explode(str2, "<TPOS>"), targ->query_possessive());
    str2 = implode(explode(str1, "<TPRO>"), targ->query_pronoun());
    str1 = implode(explode(str2, "<TOBJ>"), targ->query_objective());
    return str1 + "\n";
  case 4:
    str1 = implode(explode(list[4], "<ADV>"), adv);
    str2 = implode(explode(str1, "<ME>"), TP->SNAME);
    str1 = implode(explode(str2, "<MPOS>"), TP->query_possessive());
    str2 = implode(explode(str1, "<MPRO>"), TP->query_pronoun());
    str1 = implode(explode(str1, "<MOBJ>"), TP->query_objective());
    return str1 + "\n";
  }
}

string find_adverb(string adv, object prev) {
  int num;

  if((num = member_array(adv, adverbs_list)) == -1)
    return prev->query_adverb(adv);
  else
    return adverbs_list[num];
}

string *query_feelings_list() {
  return feelings_list;
}
