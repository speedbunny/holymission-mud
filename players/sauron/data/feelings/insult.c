string *feelingInfo() {
    int iRnd;

    iRnd=random(20);
    if(!iRnd)
        return ({
            "$Ns look$s around for someone to insult.",
            "$Ns say$s: Poor $Nv... Next door neighbour is an asshole, and \
$Pv best friend is a c**t.",
            0,
        });
    else if(iRnd<5)
        return ({
            "$Ns look$s around for someone to insult.",
            "$Ns ask$s: So which bucket did you crawl out of $Nv?",
            0,
        });
    else
        return ({
            "$Ns look$s around for someone to insult.",
            "$Ns say$s: Look $Nv, I have more guts in my little finger \
than you do in a large intestine.",
            0,
        });
}
