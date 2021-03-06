import java.util.*;
import java.io.*;

public class Souvik_Kar_Garden {

	public static void main(String[] args) {

		Scanner keyboard = new Scanner(System.in);

		int grid_rows = 8;
		int grid_cols = 8;

		//Creates two boolean grids for the orignal grid and changed
		boolean[][] grid = new boolean[grid_rows][grid_cols];
		boolean[][] changed_grid = new boolean[grid_rows][grid_cols];

		//Calls load file to load the coordinates to the the grid and prints the grid
		LoadFile(grid);
		printGarden(grid);

		String input = "yes";

		//A do-while loop that keeps running to see another day if the user wants to
		do {
			
			System.out.println("Would you like to see another day (yes or no)");
			input = keyboard.nextLine();
		
			if(input.equals("no")) 
			{
				return;
			}

			int flower_count;

			//Runs a for loop through all the spots in the matrix and then
			for(int currentRow = 0; currentRow < grid.length; currentRow++) 
			{
				for(int currentCol = 0; currentCol < grid[currentRow].length; currentCol++) 
				{
					//Gets the number of neighbors for each spot in the matrix from countNeighbors function
					flower_count = countNeighbors(grid, currentRow, currentCol);
					//Then calls the rules function to apply the rules of the day to the changed grid at that spot
					changed_grid[currentRow][currentCol] = rules(flower_count, grid[currentRow][currentCol]);
				}
			}

			System.out.println("Changed Grid");
			printGarden(changed_grid);

			//Copys the changed grid to the orignal grid matrix
			for(int rows = 0; rows < changed_grid.length; rows++) 
			{
				for(int cols = 0; cols < changed_grid[rows].length; cols++) 
				{
					grid[rows][cols] = changed_grid[rows][cols];
				}
			}
		} while(input.equals("yes"));
	}

	public static void LoadFile(boolean[][] grid_p1) 
	{
		//Creates a scanner for loading the file in
		Scanner fileIn = null;

		try {

			//Loads the file flowerlocs.txt
			File thefile = new File("flowerlocs.txt");
			fileIn = new Scanner(thefile);

		} catch(FileNotFoundException e) {
			
			//If the file isn't found print that out to the user
			System.out.println("Cannot find the file");
		}

		//Runs a while loop and gathers the row and column of each line and goes to the grid and sets that spot to true
		while(fileIn.hasNextInt()) 
		{
			grid_p1[fileIn.nextInt()][fileIn.nextInt()] = true;
		}
	}

	public static void printGarden(boolean[][] grid_p3) 
	{
		
		//Runs a for loop to print number of columns 
		for(int i = 0; i < grid_p3.length; i++) 
		{
			System.out.print("  " + i);
		}
		System.out.println();
		
		//Runs a for loop to print the matrix with x's or spaces 
		for(int rows = 0; rows < grid_p3.length; rows++) 
		{
			//Prints the rows 
			System.out.print(rows);
			for(int cols = 0; cols < grid_p3[rows].length; cols++) 
			{
				if(grid_p3[rows][cols] == true) 
				{
					System.out.print(" X ");
				}
				
				else 
				{
					System.out.print("   ");
				}
			}
			System.out.println();
		}
	}

	
	public static int countNeighbors(boolean[][] grid_p4, int currentRow, int currentCol)
	{
		//Creates two news int to hold the neighborhood positions, first set to the positions of the spot to be checked
		int new_R = currentRow;
		int new_C = currentCol;
		
		//Creates two arrays to hold the possible 8 neighbors for a cell in terms of -1,0,1
		int[] horziontal = {-1, -1, -1, 0, 1, 1, 1, 0};
		int[] vertical = {-1, 0, 1, 1, 1, 0, -1, -1};
		
		int flower_count = 0; 
		
		for(int i = 0; i < vertical.length; i++)
		{
			//After each iteration reset new_R and new_C  
			new_R = currentRow;
			new_C = currentCol;
			
			//Add the number in the array to the new_R or new_C to be checked 
			new_R += horziontal[i];
			new_C +=  vertical[i];
			
			//If the neighborhood position is valid 
			if(!(new_R < 0 || new_R >  grid_p4.length - 1 ||  new_C < 0 || new_C > grid_p4.length - 1))
			{
				//If the neighborhood position is equal to the spot that needs to be checked for neighbors 
				if(!(new_R == currentRow && new_C == currentCol))
				{
					//If the neighborhood position on the matrix is true then increment flower count by 1 
					if(grid_p4[new_R][new_C] == true)
					{
						//System.out.println("This spot is a neighbor " + new_R + ", " + new_C);
						flower_count++;
					}
				
				}
			}
		}
		return flower_count; 
	}

	public static boolean rules(int flower_count_p, boolean existing_value_p) 
	{
		//If the flower count is going to die of overcrowding or being lonely return false
		if(flower_count_p >= 4 || flower_count_p == 1 || flower_count_p == 0) 
		{
			return false;
		}

		//If a location that is empty has 3 neighbors then return true;
		if(flower_count_p == 3) 
		{
			return true;
		}

		//If the rules don't apply just copy the spot's data true or false in the matrix
		return existing_value_p;
	}
}