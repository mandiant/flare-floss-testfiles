const std = @import("std");

const backing_bytes = "ZIG_SLICE_ALPHA|ZIG_SLICE_BRAVO|ZIG_SLICE_CHARLIE";

pub fn main() void {
    const alpha: []const u8 = backing_bytes[0..15];
    const bravo: []const u8 = backing_bytes[16..31];
    const charlie: []const u8 = backing_bytes[32..49];

    std.debug.print("{s}\n", .{alpha});
    std.debug.print("{s}\n", .{bravo});
    std.debug.print("{s}\n", .{charlie});
}
