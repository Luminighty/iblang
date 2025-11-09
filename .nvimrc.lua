vim.keymap.set("n", "<F5>", "<cmd>!ib && ./main test test<CR>", { desc = "Run the app" })

vim.keymap.set("n", "<leader>br", "<cmd>!(cd ../iblang/ && ./install.sh)<CR>", { desc = "Rebuild Compiler" })
vim.keymap.set("n", "<leader>bb", "<cmd>!ib<CR>", { desc = "Build" })
