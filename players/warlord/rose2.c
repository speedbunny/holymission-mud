inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("rose");
set_short("Red rose");
  set_long("This rose shows undying devotion to the holder.....\n");
  set_weight(0);
  return 1;
}

