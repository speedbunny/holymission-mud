object victim;

wield(a) {
    switch(a->query_weapon_type()) {
        case 1:
            if(!a->query_quest_item()) {
                write("This is too much a fighters weapon!\n"); 
                return 0; 
            }
        case 0:
            if(!a->query_quest_item() && a->weapon_class()>15) {
                write("This is too much a fighters weapon!\n"); 
                return 0;
            }
    }
    return victim->wield(a);
}

query_mage_shadow() { return 1; }

chk(s) {
    return !(s->query_mage_shadow());
}


cover_it(whom) {
    object s;

    if(whom) {
        s=shadow(whom,0);
        while(s && chk(s)) s=shadow(s,0);
        if(s) {
            destruct(this_object());
            return;
        }
        shadow(whom,1);
        victim=whom;
    } else destruct(this_object());
}

get_lost() {
    unshadow();
}
