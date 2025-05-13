inherit "obj/bag";

reset(arg)
{
    ::reset(arg);
    if (!first_inventory(this_object()) )
        move_object(clone_object("players/amylaar/nutshell"),this_object());
}
