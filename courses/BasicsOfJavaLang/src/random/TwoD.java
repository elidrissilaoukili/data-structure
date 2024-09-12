import java.util.List;
import java.util.ArrayList;

public class TwoD {
    public static void main(String[] args){
    	List<List<Integer>> table = new ArrayList<>();
    	for(int i=0;i<=10;i++){
    		List<Integer> row = new ArrayList<>();
    		for(int j=0;j<=10;j++){
                row.add(i*j);
            }
    		table.add(row);
    	}
    	
        for (List<Integer> row : table) {
            System.out.println(row);
        }
    }
}