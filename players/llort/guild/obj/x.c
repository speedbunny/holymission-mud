look_info(flag) {
    if(flag) return 0;
    return ("("+COLO[type]+" aura)");
}

short(flag)
{
    string tmp;

    tmp = mon->short(flag);
    if (!tmp) return 0;
    if(flag) return tmp;
    return tmp+look_info();
}
