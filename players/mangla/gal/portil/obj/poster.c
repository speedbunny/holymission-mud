inherit "obj/treasure";

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_id("poster");
      set_alias("lovely poster");
      set_short("A poster");
      set_long("It is a poster with a picture of a building on it.\n"
		+"There is also something written on it.\n");
      set_read("It reads: Be a Biologist. You won`t regret it.\n");
      set_value(20);
      set_weight(0);
      }
