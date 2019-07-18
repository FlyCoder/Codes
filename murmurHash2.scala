def murmurHash2(data: Array[Byte], seed: Int = 0): Long = {
  val UINT_MASK = 0xFFFFFFFFL
  val UNSIGNED_MASK = 0xFF
  // 'm' and 'r' are mixing constants generated offline.
  // They're not really 'magic', they just happen to work well.
  val m = 0x5bd1e995L
  val r = 24
  var len = data.length
  // Initialize the hash to a 'random' value
  var hash = (seed ^ len) & UINT_MASK

  // Mix 4 bytes at a time into the hash
  var i = 0
  while (len >= 4) {
    var k: Long = data(i + 0) & UNSIGNED_MASK
    k |= (data(i + 1) & UNSIGNED_MASK) << 8
    k |= (data(i + 2) & UNSIGNED_MASK) << 16
    k |= (data(i + 3) & UNSIGNED_MASK) << 24

    k = (k * m) & UINT_MASK
    k ^= (k >>> r) & UINT_MASK
    k = (k * m) & UINT_MASK

    hash = (hash * m) & UINT_MASK
    hash = (hash ^ k) & UINT_MASK

    i += 4
    len -= 4
  }
  // Handle the last few bytes of the input array
  if (len == 3) hash ^= (data(i + 2) & UNSIGNED_MASK) << 16
  if (len >= 2) hash ^= (data(i + 1) & UNSIGNED_MASK) << 8
  if (len >= 1) {
    hash ^= data(i) & UNSIGNED_MASK
    hash = (hash * m) & UINT_MASK
  }
  hash ^= (hash >>> 13) & UINT_MASK
  hash = (hash * m) & UINT_MASK
  hash ^= hash >>> 15
  hash
}
