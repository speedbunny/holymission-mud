string *feelingInfo() {
    if(this_player()->query_real_name() == "sauron")
        return ({
            "$Ns work$s $Os$Sr$Sself into a frenzy.",
            "$Ns slave $V $Nv.",
            0,
        });
    else
        return ({
            "$Ns work$s $Os$Sr$Sself into a frenzy.",
            "$Ns make$s like Sauron and slave $V $Nv.",
            0,
        });
}
