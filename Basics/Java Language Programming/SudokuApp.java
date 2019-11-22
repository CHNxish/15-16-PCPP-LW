import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.text.*;
import java.lang.reflect.*;


public class SudokuApp extends JApplet{
	public static final int TEXT_NUMBER = 81;
	private JTextField[] textArray;
	private JTextField textOutput;
	private JButton solveButton;


	public SudokuApp(){
		setLayout(null);
		textArray = new JTextField[TEXT_NUMBER];
		for(int i = 0; i < TEXT_NUMBER; i++){
			textArray[i] = new JTextField();
			textArray[i].setDocument(new PlainDocumentFilter(1));
			textArray[i].setBounds(50 * (int)(i % 9) + 1, 50  * (int)(i / 9) + 1, 50 - 2, 50 -2);
			add(textArray[i]);
		}

		textOutput = new JTextField("输入待解决的数独");
		textOutput.setBounds(0 + 1, 450 + 1, 400 - 2, 50 - 2);
		textOutput.setEditable(false);
		solveButton = new JButton("Solve");
		solveButton.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				int[][] intArray = new int[9][9];
				for(int i = 0; i < TEXT_NUMBER; i++){
					if(textArray[i].getText().length() == 1){
						intArray[(int)(i / 9)][i % 9] = Integer.parseInt(textArray[i].getText());
					}
					else{
						intArray[(int)(i / 9)][i % 9] = 0;
					}
				}

				if(SolveSudoku(intArray, 0, 0)){
					for(int i = 0; i < TEXT_NUMBER; i++){
						textArray[i].setText(intArray[(int)(i / 9)][i % 9] + "");
					}
					textOutput.setText("数独已被解决");
				}
				else{
					textOutput.setText("数独无法被解决");
				}
			}
		});
		solveButton.setBounds(400 + 1, 450 + 1, 50 - 2, 50 - 2);

		add(textOutput);
		add(solveButton);
	}

	private boolean SolveSudoku(int[][] intArray, int row, int col){
		if(row < 9){

			for(int i = 0; i < 9; i++){
					for(int j = 0; j < 9; j++){
						System.out.print(intArray[i][j] + " ");
					}
					System.out.println();
			}
			System.out.println();

			if(intArray[row][col] != 0){
				return SolveSudoku(intArray, row + (int)((col + 1) / 9), (col + 1) % 9);
			}
			else{
				for(int i = 1; i <= 9; i++){
					if(sudokuInRow(intArray, row, col, i) && sudokuInColumn(intArray, row, col, i) && sudokuInPalace(intArray, row, col, i)){
						intArray[row][col] = i;
						if(SolveSudoku(intArray, row + (int)((col + 1) / 9), (col + 1) % 9) == true){
							return true;
						}
					}
				}
				intArray[row][col] = 0;
				return false;
			}
		}

		return true;
	}

	private boolean sudokuInRow(int[][] intArray, int row, int col, int n){
		for(int i = 0; i < 9; i++){
			if(intArray[row][i] == n)
				return false;
		}
		return true;
	}
	private boolean sudokuInColumn(int[][] intArray, int row, int col, int n){
		for(int i = 0; i < 9; i++){
			if(intArray[i][col] == n)
				return false;
		}
		return true;
	}
	private boolean sudokuInPalace(int[][] intArray, int row, int col, int n){
		int newRow = (int)(row / 3) * 3;
		int newCol = (int)(col / 3) * 3;

		for(int i = newRow; i < newRow + 3; i++){
			for(int j = newCol; j < newCol + 3; j++){
				if(intArray[i][j] == n)
					return false;
			}
		}
		return true;
	}

	class PlainDocumentFilter extends PlainDocument{
		int count;

		public PlainDocumentFilter(int count){
			super();
			this.count = count;
		}

		public void insertString(int offs, String str, AttributeSet attr) throws BadLocationException{
			if(str == null)
				return;

			if(this.getLength() + str.length() <= count){
				char[] charArray = str.toCharArray();

				int length = 0;
				for(int i = 0; i < charArray.length; i++){
					if(charArray[i] >= '0' && charArray[i] <= '9'){
						charArray[length++] = charArray[i];
					}
				}
				super.insertString(offs, new String(charArray, 0, length), attr);
			}
		}
	}
}