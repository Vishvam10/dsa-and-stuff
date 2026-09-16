class Solution {
public:
    bool solve(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy)
            return false;

        if (tx == sx && ty == sy)
            return true;

        if (tx > ty)
            return solve(sx, sy, tx - ty, ty);

        return solve(sx, sy, tx, ty - tx);
    }

    bool reachingPoints(int sx, int sy, int tx, int ty) {
        // Don't do forward as it explodes, do reverse as it's
        // deterministc ... for example, if tx > ty => previous step
        // must be (x + y, y). So, reversing that gives us (tx - ty)
        // Similarly for tx > tx as well

        // return solve(sx, sy, tx, ty);

        while (sx < tx && sy < ty) {
            if (tx < ty) ty %= tx;
            else tx %= ty;
        }

        return (
            (sx == tx && sy <= ty && (ty - sy) % sx == 0) ||
            (sy == ty && sx <= tx && (tx - sx) % sy == 0)
        );

    }
};
