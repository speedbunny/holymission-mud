 /* sanctuary */

inherit "/players/whisky/obj/std_shadow";


hit_player(dam,kind)
{
    return me->hit_player( (dam/2),kind);
}

void end_shadow()
{
     tell_object(me,
     "The white aura around your body fades happily away.\n");
     ::end_shadow();
}

int sanctuary()
{
    return 1;
}

