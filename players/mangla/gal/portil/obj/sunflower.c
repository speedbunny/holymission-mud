inherit "obj/treasure";

query_quest_item() { return 1; }

    reset(arg) {
     ::reset(arg);
     if (arg) return;

      set_id("seed");
      set_alias("sunflower seed");
      set_short("A sunflower seed");
      set_long("It is a small seed with black and white stripes on it.\n");
      set_value(10);
      set_weight(0);
      }
