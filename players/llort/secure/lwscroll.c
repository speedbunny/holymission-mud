inherit "/obj/thing";

reset ( tick )
{
    ::reset( tick );
    if( tick ) return;

    set_name("scroll");
    set_alt_name("limited-wish");
    set_alias("scroll of limited-wish");
    set_short("Scroll of limited-wish");
    set_long("This seems to be a limited wish scroll. It humms powerfully.\n");
    set_value(1);
    set_weight(0);
}

init()
{
    ::init();

    add_action("recite","recite");
}

recite(arg)
{
  write("These are no longer valid items.\n" +
         "-Mangla\n\n");
  destruct(this_object());
  return 1;
}
