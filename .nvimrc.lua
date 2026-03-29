vim.keymap.set("n", "<F5>", "<cmd>!cargo run -- -e<CR>", { desc = "Run the app" })
vim.keymap.set("n", "<F6>", "<cmd>!./install.sh<CR>", { desc = "Install the app" })
vim.keymap.set("n", "<leader>bb", "<cmd>!cargo build<CR>", { desc = "Run the app" })
vim.keymap.set("n", "<leader>br", "<cmd>!./install.sh<CR>", { desc = "Install the app" })
