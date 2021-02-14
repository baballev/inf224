
import javax.swing.*;


import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.UnknownHostException;
import java.util.*;

public class MainWindow extends JFrame implements ActionListener {
	JButton button1 = null;
	JButton button2 = null;
	JButton button3 = null;
    private static final long serialVersionUID = 1L; 

	JTextArea text_area = null;
	JScrollPane scroll_bar = null;
	JMenuBar menu_bar = null;
	JToolBar tool_bar = null;
	
	JMenu menu1 = null;
	JMenu menu2 = null; 
	
	JMenuItem menuItem = null;
	JMenuItem menuItem2 = null;
	JMenuItem menuItem3 = null;
	JMenuItem menuItem4 = null;
	
	Client client = null;
	
	public static void main(String[] argv) throws UnknownHostException, IOException {
		MainWindow window = new MainWindow();
	}
	
	public MainWindow() throws UnknownHostException, IOException {
		menu_bar = new JMenuBar();
		tool_bar = new JToolBar();
		menu1 = new JMenu("Menu 1");
		add(menu1);
		menu2 = new JMenu("Menu 2");
		add(menu2);
		
		menuItem = new JMenuItem("Display");
		menuItem.addActionListener(this);
		menuItem2 = new JMenuItem("Play");
		menuItem2.addActionListener(this);
		menuItem3 = new JMenuItem("Display");
		menuItem3.addActionListener(this);
		menuItem4 = new JMenuItem("Play");
		menuItem4.addActionListener(this);
		
		menu1.add(menuItem);
		menu1.add(menuItem2);
		menu2.add(menuItem3);
		menu2.add(menuItem4);
		
		menu_bar.add(menu1);
		menu_bar.add(menu2);		
		add(tool_bar, BorderLayout.NORTH);
		setJMenuBar(menu_bar);

		
		
		text_area = new JTextArea(15, 30);
		add(text_area, BorderLayout.CENTER);
		button1 = new JButton("Quitter");
		add(button1, BorderLayout.PAGE_END);
		button2 = new JButton("Display");
		add(button2, BorderLayout.WEST);
		button3 = new JButton("Play");
		add(button3, BorderLayout.EAST);
		
		button1.addActionListener(this);
		button2.addActionListener(this);
		button3.addActionListener(this);
		
		scroll_bar = new JScrollPane(text_area);
		add(scroll_bar);
		
		
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Set-Top Box multimedia");
		pack();
		setVisible(true);
	
		
		client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
		client.send("create abc");
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		
		if (e.getSource() == button1) {
			System.exit(0);
		}
		else if (e.getSource() == button2 || e.getSource() == menuItem || e.getSource() == menuItem3) {
			JTextField text_field = new JTextField();
			Object[] fields = { "Nom du multimedia: ", text_field };
			int newPane = JOptionPane.showConfirmDialog(null, fields, "Display multimedia", JOptionPane.OK_CANCEL_OPTION);
			boolean done = false;
			while (!done) {
			if (newPane == JOptionPane.YES_OPTION) {
				String t = text_field.getText();
				String response = this.client.send("display " + t);
				
				text_area.setText(text_area.getText() + response + "\n");
				done = true;
		
			} else if (newPane == JOptionPane.CANCEL_OPTION || newPane == JOptionPane.CLOSED_OPTION) 
				done = true;
			}
		}
			
		else if (e.getSource() == button3 || e.getSource() == menuItem2 || e.getSource() == menuItem4) {
			JTextField text_field = new JTextField();
			Object[] fields = { "Nom du multimedia: ", text_field };
			int newPane = JOptionPane.showConfirmDialog(null, fields, "Play multimedia", JOptionPane.OK_CANCEL_OPTION);
			boolean done = false;
			while (!done) {
			if (newPane == JOptionPane.YES_OPTION) {
				String t = text_field.getText();
				String response = this.client.send("play " + t);
				text_area.setText(text_area.getText() + response + "\n");
				done = true;
		
			} else if (newPane == JOptionPane.CANCEL_OPTION || newPane == JOptionPane.CLOSED_OPTION) 
				done = true;
			}
			
		} 
		else {
			
		}
		pack();
	}
}

