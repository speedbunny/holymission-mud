inherit "obj/treasure";
int alchemic_value;

reset(arg) {
    ::reset(arg);
    if (arg)
        return;
    set_alt_name("bottle");
    set_weight(1);
}

query_alchemic()  {  return 1;  }

query_alchemic_value()  {  return alchemic_value;  }

set_alchemic_value(arg)  {  alchemic_value = arg;  return 1;  }

