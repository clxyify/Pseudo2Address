/* IDA dumped version (offsets change once in a week) */

void *__fastcall pseudo2_dumped(DWORD *a1, int a2) /* orignally dumped from IDA */
{
  int v3;
  unsigned int v5;
  int v6;
  int v7;
  int v8;
  int v9;

  switch (a2)
  {
    case -10002: // lua definitions
      v9 = (unsigned int)(a1 + 7) ^ a1[7];
      *(DWORD *)(v9 + 1536) = a1[16];
      *(DWORD *)(v9 + 1548) = 6;
      return (void *)(((unsigned int)(a1 + 7) ^ a1[7]) + 1536);
    case -10001:
      v5 = (unsigned int)(a1 + 7);
      v6 = a1[4];
      v7 = (unsigned int)(a1 + 7) ^ a1[7];
      if ( v6 == a1[9] )
        v8 = a1[16];
      else
        v8 = *(DWORD *)(**(DWORD **)(v6 + 4) + 12);
      *(DWORD *)(v7 + 1536) = v8;
      *(DWORD *)(v7 + 1548) = 6;
      return (void *)((v5 ^ *(DWORD *)v5) + 1536);
    case -10000:
      return (void *)(((unsigned int)(a1 + 7) ^ a1[7]) + 1552);
    default: // if no matching lua index's were found
      v3 = **(DWORD **)(a1[4] + 4);
      if ( -10002 - a2 > *(unsigned __int8 *)(v3 + 4) )
        return 0;
      else
        return (void *)(v3 + 16 * (-10002 - a2 + 1));
  }
}

/* thanks roblox luau source */
static LUAU_NOINLINE TValue* pseudo2(lua_State* L, int idx)
{
    api_check(L, lua_ispseudo(idx));
    switch (idx)
    { /* pseudo-indices */
    case LUA_REGISTRYINDEX:
        return registry(L);
    case LUA_ENVIRONINDEX:
    {
        sethvalue(L, &L->global->pseudotemp, getcurrenv(L));
        return &L->global->pseudotemp;
    }
    case LUA_GLOBALSINDEX:
    {
        sethvalue(L, &L->global->pseudotemp, L->gt);
        return &L->global->pseudotemp;
    }
    default:
    {
        Closure* func = curr_func(L);
        idx = LUA_GLOBALSINDEX - idx;
        return (idx <= func->nupvalues) ? &func->c.upvals[idx - 1] : cast_to(TValue*, luaO_nilobject);
    }
    }
}
