import java.util.*;

public class SouvikKar_Perfect_Square {

	public static void main(String[] args) {

		//A hardcoded square matrix 
		int[][] square = { { 16, 3, 2, 13 }, { 5, 10, 11, 8 }, { 9, 6, 7, 12 }, { 4, 15, 14, 1 } };
		
		//Creates a boolean to check if isPerfect returns true or false
		boolean check = isPerfect(square);
		
		//If check is true it is a perfect square 
		if(check == true)
		{
			System.out.println("Perfect Square Matrix");
		}
		
		else
		{
			System.out.println("Not A Perfect Square Matrix");
		}
	}

	public static boolean isUnique(int[][] square) {

		//Creates helper int called found to count number of occurences of a possible number
		int found = 0; 
		
		//Runs a for loop through 1 through the matrix's length squared 
		for(int i = 1; i <= square.length * square.length; i++)
		{
			found = 0;
			//Checks for the number i in the matrix 
			for(int row = 0; row < square.length; row++) 
			{
				for(int col = 0; col < square[row].length; col++) 
				{
					//If the number is found in any part of the matrix increment found by 1
					if(i == square[row][col])
					{
						found++; 
					}
				}
			}
			
			//If the number appears more than once or its not found return false
			if(found > 1 || found == 0)
			{
				return false;
			}
		}
		
		return true;
	}

	
	public static int sumRow(int[][] square, int row)
	{
		int sum = 0;
		
		//Runs a for loop through the columns of the matrix and its that spot to the sum
		for(int col = 0; col < square[row].length; col++)
		{
			sum += square[row][col];
		}
		
		//Returns the sum of the Row
		return sum; 
	}
	
	public static int sumCol(int[][] square, int col)
	{
		int sum = 0;
		
		//Runs a for loop through the rows of the matrix and its that spot to the sum
		for(int row = 0; row < square.length; row++)
		{
			sum += square[row][col];
		}
		
		//Returns the sum of the Column 
		return sum; 
	}
	
	public static int forwardDiag(int[][] square_p2)
	{
		int sum = 0; 
		
		//Runs a for loop though the matrix of rows and columns 
		for(int row = 0; row < square_p2.length; row++)
		{
			for(int col = 0; col < square_p2[row].length; col++)
			{
				//If the row and column variables are equal, add that spot to the sum 
				if(row == col)
				{
					sum += square_p2[row][col];
				}
			}
		}
		
		return sum; 
	}
	
	public static int backDiag(int[][] square_p1)
	{
		int sum = 0; 
		
		//Runs a for loop from the bottom corner of the matrix to the very top right to get the sum of the backDiagonal 
		for(int row = square_p1.length - 1; row >= 0; row--)
		{
			for(int col = 0; col < square_p1.length; col++)
			{
				//If the row + the column is equal to the length of the matrix - 1 add that spot to the sum 
				if(row + col == square_p1.length - 1)
				{
					sum += square_p1[row][col];
				}
			}
		}
		return sum; 
	}
	
	public static boolean isPerfect(int[][] square)
	{
		//A boolean set equal to check if the matrix is valid or invalid 
		boolean check = isUnique(square);
		
		//If the matrix isn't valid immediatly false 
		if(check == false)
		{
			return false; 
		}
		
		//Creates a sum for the first row of the matrix 
		int sum_firstrow = sumRow(square, 0);
			
		//Run a for loop through all the rows not including the 1st one and checks if the sum of the first row is not equal to what sumRow is returning 
		for(int row = 1; row < square.length; row++)
		{
			if(sum_firstrow  != sumRow(square, row))
			{
				return false; 
			}
		}
			
		///Run a for loop through all the columns not including the 1st one and checks if the sum of the first row is not equal to what sumCol is returning 
		for(int col = 0; col < square.length; col++)
		{
			if(sum_firstrow  != sumCol(square, col))
			{
				return false; 
			}
		}
			
		//If the sum of forwardDiag is not equal to the sum of the first row return false
		if((forwardDiag(square) != sum_firstrow ))
		{
			return false;  
		}
		
		//If the sum of backDiag is not equal to the sum of the first row return false
		if((backDiag(square) != sum_firstrow ))
		{
			return false; 
		}
		
		return true; 
	}
}