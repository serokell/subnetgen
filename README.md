# subnetgen

Generate IPv4 and IPv6 subnetworks.

Rationale behind this program is to make sure networks are composable: say, so
that someone can daisy-chain VPNs, local networks, and it will just work while
also keeping all peers addressable.

IPv6 subnetworks are [RFC 4193][] (ULA) conformant.

[RFC 4193]: https://tools.ietf.org/html/rfc4193

Bytes are securely generated via `getentropy(3)`. This program will only work on
Linux and OpenBSD.

| Network | Flag | N, 50% collision chance |     Network capacity |
| ------- | ---- | ----------------------- | -------------------- |
| IPv4    | `-4` |                     300 |                  254 |
| IPv6    | `-6` |               1 230 000 | more than septillion |

As you can see, IPv4 networks generated by this tool only provide limited
capacity. You can trade some uniqueness for more peers by decrementing CIDR
prefix, see [CIDR.xyz](https://cidr.xyz).

Flags are processed in order and can be repeated. For example, `subnetgen -44664`
will print two IPv4 subnets, then two IPv6 subnets, and then one more IPv4 subnet,
in that order, each on separate line.

If you want to calculate chance of collision, refer to [birthday problem][].

[birthday problem]: https://en.wikipedia.org/wiki/Birthday_problem
