inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("emerald");
  set_short("large emerald");
  set_long("A large deep green jewel. It's pefectly cut in a\n"+ 
  "sphere shape. Looks as if it's quite valuable, maybe TOO\n"+
  "valuable to sell!\n");
  set_value(2000);
  set_weight(1);
  return 1;
}

