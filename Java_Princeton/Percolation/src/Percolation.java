
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
public class Percolation {
    private final int[][]directions = {{1,0}, {-1,0},{0,1},{0,-1}};
    //virtual starts,ends, reduce the call of UnionFind
    private int Vtop = 0;
    private int Vbottom;
    private boolean[][] openstatus; // true means open, flase means close
    private int n; //grids length size
    private WeightedQuickUnionUF uf, test; //uf include Virtual top/botm,  test only include vtop.
    private int count; //already opened site

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n){
        if(n<0){
            throw new IllegalArgumentException();
        }
        this.n = n;
        openstatus = new boolean[n+1][n+1];
        Vbottom = n*n +1;
        //unionFind set needs n * n + 2 nodes，0 means vtop，n^2 means sites，n^2+1 means virtualbottom
        uf = new WeightedQuickUnionUF(bottom+1);
        test = new WeightedQuickUnionUF(bottom+1);

    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        if (row <= n && col <= n & row >= 1 & col >= 1) {
            if (!openstatus[row][col]) {
                openstatus[row][col] = true;
                this.count++;
                // 将第一层与虚拟起点连接，最后一层与虚拟终点连接
                int unionIndex = (row - 1) * n + col;
                if (row == 1) { // if at row 1, union virtual top
                    uf.union(unionIndex, Vtop);
                    test.union(unionIndex, Vtop);
                }
                if (row == n) { // if at last row, union virtual bottom
                    uf.union(unionIndex, Vbottom);
                    test.union(unionIndex, Vbottom);
                }

                // union possible neighbor(s)
                if (row > 1 && isOpen(row - 1, col)) {
                    uf.union(unionIndex, unionIndex - n); // union with above
                    test.union(unionIndex, unionIndex - n);
                }
                if (row < n && isOpen(row + 1, col)) {
                    uf.union(unionIndex, unionIndex + n); // union with down
                    test.union(unionIndex, unionIndex + n);
                }
                if (col > 1 && isOpen(row, col - 1)) {
                    uf.union(unionIndex, unionIndex - 1); // union with left
                    test.union(unionIndex, unionIndex - 1);
                }
                if (row < n && isOpen(row, col + 1)) {
                    uf.union(unionIndex, unionIndex + 1); // union with right
                    test.union(unionIndex, unionIndex + 1);
                }
            }
        }
        else{
            throw new IllegalArgumentException();
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col){
        boolean flag = false;
        if(row <= n && col <= n && row >= 1 && col >= 1){
            if(openstatus[row][col])
                flag = true;
            return flag;
        }
        else{
            throw new IllegalArgumentException();
        }
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col){
        if (row <= n && col <= n && row >= 1 && col >= 1)
        {
            boolean flag = false;
            int unionIndex = (row - 1) * n + col;
            if (openstatus[row][col] && test.find(unionIndex) == test.find(Vtop))
                flag = true;
            return flag;
        }
        else {
            throw new IllegalArgumentException();
        }
    }

    // returns the number of open sites
    public int numberOfOpenSites(){
        return this.count;
    }

    // does the system percolate?
    public boolean percolates(){
        boolean flag = false;
        if(uf.find(Vtop) == uf.find(Vbottom)){
            flag = true;
        }
        return flag;
    }

    // test client (optional)
    public static void main(String[] args){
        Percolation p;
        p= new Percolation(2);
        p.open(2, 1);
        p.open(2, 2);
        p.open(1, 2);
        assert p.percolates();
        // Backwash
        // (3, 1) 通过虚拟终点与起点连接，但它其实不是 full 的
        p = new Percolation(3);
        p.open(1, 1);
        p.open(1, 2);
        p.open(1, 3);
        p.open(2, 3);
        p.open(2, 2);
        p.open(3, 3);
        p.open(3, 1);
        assert !p.isFull(3, 1);
        assert p.percolates();
    }
}
