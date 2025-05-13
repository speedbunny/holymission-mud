// Mirror Image Shadow
// id: mirror_image
// attr-msg: mirror image
// look-info: short shadowed
// no multiple shadows

#define NRS ({ "", "two", "three", "four", "five", "six", "seven", "eight",\
               "nine", "many" })

inherit "/obj/std_shadow";

int nr_of_images;

start_shadow(who, time,n)
{
    set_effect_msg("mirror image");
    nr_of_images = n;
    return ::start_shadow(who, time, "mirror_image",0);
}

query_show_short() { return 1; }

short()
{
    return NRS[(nr_of_images > 9 ? 9 : nr_of_images)]+" "+
           capitalize(me->query_name_true())+"s";
}

hit_player(dam,kind,elem)
{
// I've been hit
    if(random((nr_of_images+1)*10)<10)
    {
        return me->hit_player(dam,kind,elem);
    } 
// an image destroyed
    else
    {
        nr_of_images--;
        tell_object(me, "One of your mirror images disappears.\n");
        write ( "As you strike "+me->query_name_true()+" you notize it was"+
                " an image!\n");
        say( "One of "+me->query_name_true()+"s images disappears.\n",me,me,"");
        if(nr_of_images < 1) end_shadow(this_object());
        return 0;
    }
}

end_shadow(o) {
    if(me) tell_object(me, "You feel lonely again!\n");
    ::end_shadow(o);
}
