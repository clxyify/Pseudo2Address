# Pseudo2Address

This repo contains the `lua_State` edition for pseudo2addr, and the `c++ dumped` version of pseudo2addr.

How does it work? Well pseudo2addr is actually friends with index2addr, they do similar stuff.

**Index2addr** will check if the index is greater then NULL, -10000, otherwise pass on the function to `pseudo2addr.`

It is used for 2 cases, mostly acting like `index2addr` it has it's own address which you can find in IDA.

You can **check** out the pseudocode dumped for usage, it does use `rL` but you can figure it out.

# Getting Pseudo2Address

Signature Scan -> `81 FA EE D8 FF FF` and go to the function it is being called as.

**Note:** this signature might be outdated in the next few updates. Use it while you can.
