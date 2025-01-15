LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY LAB1 IS
	PORT(
		clock, reset, btn_i : IN std_logic;
		led_o : OUT std_logic_vector(9 DOWNTO 0)
	);
END LAB1;

ARCHITECTURE STRUCTURE OF LAB1 IS

	--COMPONENT
	COMPONENT Lab1_sys IS
		port (
			button_export : in  std_logic; --BTN
			clk_clk    : in  std_logic; -- clk
			led_export : out std_logic_vector(9 DOWNTO 0); -- LED
			reset_reset_n : in  std_logic  -- reset_n
		);
	END COMPONENT Lab1_sys;
		
	--SIGNAL DECLARATION
	
	--INSTANTIATION AND WIRING	
	BEGIN
		Lab1_sys_inst : Lab1_sys PORT MAP(btn_i, clock, led_o, reset);
END STRUCTURE;