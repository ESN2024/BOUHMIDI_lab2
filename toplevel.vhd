library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity toplevel is
	port (
		clk      : in  std_logic                     := '0'; --   clk.clk
		reset: in  std_logic                     := '0'; -- reset.reset_n
		seg    : out std_logic_vector(20 downto 0)         --   seg.export
	);
end entity toplevel;


architecture rtl of toplevel is

    component lab2 is
        port (
            clk_clk       : in  std_logic                     := 'X'; -- clk
            reset_reset_n : in  std_logic                     := 'X'; -- reset_n
            seg_export    : out std_logic_vector(11 downto 0)         -- export
        );
    end component lab2;
	 
	 component bin_to_7seg is
		  port (
				bcd : in std_logic_vector(3 downto 0); 
				leds : out std_logic_vector(6 downto 0)
		);
	 end component bin_to_7seg;

	 signal bcd_int : std_logic_vector(11 downto 0); 
	 
begin
		u0 : component lab2
			 port map (
				clk_clk       => clk,       --   clk.clk
				reset_reset_n => reset, -- reset.reset_n
				seg_export    => bcd_int     --   seg.export
			  );
		u1 : component bin_to_7seg
			port map (
				bcd => bcd_int(11 downto 8),
				leds => seg(20 downto 14)
			);
		u2 : component bin_to_7seg
			port map (
				bcd => bcd_int(7 downto 4),
				leds => seg(13 downto 7)
			);

		u3 : component bin_to_7seg
			port map (
				bcd => bcd_int(3 downto 0),
				leds => seg(6 downto 0)
			);
end architecture rtl;
