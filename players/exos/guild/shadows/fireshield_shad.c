// Fireshield 
// gives 'who' a fireshield of type 'kind' for 'time' seconds
// id: fireshield
// attr-msg and look-info are set depending on type
// non multiple

#define TYPE ({ "no idea","hot","electric","cold","acid" })
#define COLO ({ "translucent","red","blue","white","black" })
#define SUSP ({ 0, 3, 4, 1,2 })

inherit "/obj/std_shadow";

int type;

start_shadow(who, tim, kind)
{
    type = kind;
    if(!type || type>4) type=1;	// default heat
    set_look_info("("+COLO[type]+" aura)");
    set_effect_msg("fireshield ("+COLO[type]+")");
    return ::start_shadow(who, tim, "fireshield");
}

hit_player(x,kind,elem) {
    int dam;
   
    if(elem && intp(elem)) elem=({ elem }); 
    if(elem && member_array(type,elem)!=-1) x/=2;
    if(elem && member_array(SUSP[type],elem)!=-1) x*=2;
    dam=me->hit_player(x,kind);
    if(this_player()!=me && kind==0 && dam>0) {
        this_player()->hit_player(dam*2,5,({ type, 12 }) );
        if(this_player())
            tell_object(this_player(),
                "You wound yourself badly on the "+COLO[type]+
                " aura of your opponent.\n");
    }
    return dam;
}

end_shadow(o) {
    if(me) tell_object(me, "Your fireshield wears off!\n");
    ::end_shadow(o);
}

