inherit "obj/armour";

int heal_left;

reset(arg) {
 if(arg) return 1;
 ::reset(arg);
 set_name("ring");
 set_alias("ruby ring");
 set_type("ring");
 set_short("A Ruby Ring");
 set_size(0);
 set_ac(0);
 heal_left = 500+random(250);
}

init() {
  ::init();
  add_action("read"); add_verb("read");
}

query_value() { return 1000+heal_left*2; }

long() {
  write("This is a small gold ring set with a single red ruby.\n");
  write("There are small runes inscribed on the inside of the band.\n");
  if(heal_left >= 0)
    write("The ruby is glowing brightly.\n");
  else 
    write("The ruby is dull and lifeless.\n");
  return 1;
}

wear(str) {
  if(!id(str)) return;
  ::wear(str);
  if(worn)
    set_heart_beat(1);
  return 1;
}

drop(silently) {
  ::drop(silently);
  set_heart_beat(0);
  return 0;
}

remove(str) {
  if(!id(str)) return;
  ::remove(str);
  set_heart_beat(0);
  return 1;
}

query_info() {
 write("This is a ring of regeneration. If you wear it and you are\n");
 write("wounded, it will heal you faster than normal.\n");
 return;
}

read(str) {
 if(!id(str) && str !="runes") return 0;
 write("The runes seem to say:\n");
 write("When he whom for the ring is worn is wounded now, not dead\n");
 write("more wounds will heal than if it be not worn at all.\n");
 return 1;
} 

heart_beat() {
 int max_hp, hp, amount;
 if(!worn) {
	set_heart_beat(0);
	return 1;
 }
 if(heal_left <= 0) {
   if(worn_by)
     tell_object(worn_by,"Your ruby ring grows cold and lifeless.\n");
   set_heart_beat(0);
   return 1;
 }
 hp = worn_by->query_hp();
 max_hp = worn_by->query_max_hp();
 if(hp < max_hp) {
	amount = random(3)+2;
	worn_by->heal_self(amount);
	heal_left -= amount;
 }
 return 1;
}
