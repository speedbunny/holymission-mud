inherit "obj/soft_drink";

reset(arg) {
    ::reset(arg);
    if(arg)  return;
    name="milk";
    short_desc="A bottle of milk";
    long_desc="Figley lost this milk.\n";
    strength=5;
}
