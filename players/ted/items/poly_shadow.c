static object owner;
static string own_name, newtitle, newrace;
static object arm_name;

set_owner(ob) {
  owner = ob;
  own_name = capitalize(owner->query_name());
  shadow(owner, 1);
  call_out("new_shadow", 3600);
}

new_shadow() {
  tell_object(owner, "\n\nYou suddenly return to your old self!!\n\n");
  destruct(this_object());
}

query_polymorph() { return 1; }
new_title(str) { newtitle = str; }
new_race(str) { newrace = str; }

score() {
	string          tmp, tmp2, temp_class_name;
	int		test, high, low, temp_level;

	if (owner->query_ghost()) {
		write("You are in an immaterial state with no scores.\n");
		return 1;
	}
	temp_class_name = owner->query_class_name();
	temp_level = owner->query_level();
  write(short() +"\n");
	write("------------------------------------------------------------\n");
	write("Level:  "+temp_level+"\n");
  if(temp_level >= 30)
	write("EXP:    "+owner->query_exp()+"\n");
  else {
    if(temp_class_name == "adventurer" || temp_class_name == "none" || !temp_class_name) {
      high = call_other("room/adv_guild","get_next_exp",temp_level);
      if(temp_level >= 1)
        low = call_other("room/adv_guild","get_next_exp",temp_level-1);
    } else {
      high = call_other("obj/guild/"+temp_class_name+"_guild","get_next_exp",temp_level);
      if(temp_level >= 1)
        low = call_other("obj/guild/"+temp_class_name+"_guild","get_next_exp",temp_level-1);
    }
    test = 100 - (((high - owner->query_exp()) * 100) /(high - low));
    if(test <= 0)
      tmp2 = "You one level higher than your experience";
    else
      tmp2 = "You have "+test+"% of the experience needed for next level";
    if(!high && !low)
      tmp2 = "There is an error in your class name! Tell a Wizard!";
	write(tmp2+"\n");
  }
	write("Max/HP: "+owner->query_hit_point()+"/"+owner->query_max_hp()+
	"    Max/SP:  "+owner->query_spell_points()+"/"+owner->query_max_sp()+"\n");
	write("Money:  "+owner->query_money()+
	"   ("+((temp_level+owner->query_str())* 2000+5000)+")\n");
	write("Guild:  "+temp_class_name+"\n");
	write("Race:   "+newrace+"\n");
	write("Size:   "+owner->query_size()+"\n");
	write("Align:  "+owner->query_altitle()+"\n");
	write("Str: "+owner->query_str()+"\tInt: "+owner->query_int()+
	"\tWis: "+owner->query_wis()+"\n");
	write("Dex: "+owner->query_dex()+"\tCon: "+owner->query_con()+
	"\tChr: "+owner->query_chr()+"\n");
	write("Wimpy:  "+owner->query_wimpy()+"% \n");
	owner->show_age();
	return 1;
}

long() {
	string          cap_pronoun;
	int		temp_hp, temp_max_hp;

	temp_hp = owner->query_hit_point();
	temp_max_hp = owner->query_max_hp();
	cap_pronoun = capitalize(owner->query_pronoun());
	write(short()+" ("+owner->query_gender_string()+") ("+owner->query_race()+").\n");
	if (owner->query_ghost() || owner->query_frog())
		return;
	if (temp_hp < temp_max_hp / 10) {
		write(cap_pronoun + " is in very bad shape.\n");
		return;
	}
	if (temp_hp < temp_max_hp / 5) {
		write(cap_pronoun + " is in bad shape.\n");
		return;
	}
	if (temp_hp < temp_max_hp / 2) {
		write(cap_pronoun + " is not in a good shape.\n");
		return;
	}
	if (temp_hp < temp_max_hp - 20) {
		write(cap_pronoun + " is slightly hurt.\n");
		return;
	}
	write(cap_pronoun + " is in good shape.\n");
}

short() {
  if(owner->query_invis()) return 0;
  return own_name+" "+newtitle+" (Mortal)";
}

query_race() { return newrace; }
query_title() { return newtitle; }
query_pretitle() { return ""; }

wield(ob) {
  tell_object(owner,"You feel your natural attack is MUCH better than that!!!\n");
  ob->un_wield();
  return 1;
}
